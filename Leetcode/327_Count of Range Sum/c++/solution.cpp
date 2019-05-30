/*******************
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class SegmentTreeNode {
public:
    long min;
    long max;
    int count; //number of values in [min, max]
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(long min, long max, int count) {
        this->min = min;
        this->max = max;
        this->count = count;
        left = right = nullptr;
    }
};

// based on segment tree
class Solution1 {
    SegmentTreeNode *root;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) 
            return 0;
        unordered_set<long> ssum;
        long tmpSum = 0;
        for (auto n: nums) {
            tmpSum += n;
            ssum.insert(tmpSum);
        }
        // copy the set to a vector
        vector<long> sum;
        for (auto s: ssum) {
            sum.push_back(s);
        }
        sort(sum.begin(), sum.end());
        // build a segment tree using the sorted sums
        root = build(sum, 0, sum.size() - 1);
        // next count the number of sums based on low + sum[j] <= sum[i] <= high + sum[j], i > j
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            modify(root, tmpSum);
            tmpSum -= nums[i];
            count += query(root, lower + tmpSum, upper + tmpSum);
        }
        return count;
    }
    
    SegmentTreeNode* build(vector<long> &sum, int start, int end) {
        SegmentTreeNode *root = new SegmentTreeNode(sum[start], sum[end], 0);
        if (start == end) {
            return root;
        } else {
            int middle = (start + end) / 2;
            root->left = build(sum, start, middle);
            root->right = build(sum, middle + 1, end);
            return root;
        }
    }
    
    void modify(SegmentTreeNode *root, long value) {
        if (root == nullptr || value < root->min || value > root->max) return;
        // now value is between root->min and root->max
        root->count += 1;
        if (root->min == root->max) {
            return;
        } else {
            modify(root->left, value);
            modify(root->right, value);
        }
    }
    
    int query(SegmentTreeNode *root, long min, long max) {
        if (root == nullptr || max < root->min || min > root->max) 
            return 0;
        if (min <= root->min && max >= root->max) 
            return root->count;
        return query(root->left, min, max) + query(root->right, min, max);
    }
};

// based on merge sort
class Solution2 {
public:
    
    void merge(vector<long>& sums, int start, int end, vector<long>& temp){
        int mid = (end-start)/2+start;
        
        int i = start;
        int j = mid+1;
        int index = start; 
        while(i<=mid && j<=end){
            if(sums[i] <= sums[j]){
                temp[index++] = sums[i++];
            }else{
                temp[index++] = sums[j++];
            }
        }
        while(i<=mid){
            temp[index++] = sums[i++];
        }
        while(j<=end){
            temp[index++] = sums[j++];
        }
        for(int i = start; i <= end; i++){
            sums[i] = temp[i];
        }
    }
    
    void mergeSort(vector<long>& sums, int start, int end, vector<long>& temp, int& result, int lower, int upper){
        if(start >= end){
            return ;
        }
        int mid = (end-start)/2 + start;
        mergeSort(sums, start, mid, temp, result, lower, upper);
        mergeSort(sums, mid+1, end, temp, result, lower, upper);
        
        int j = mid+1;
        int k = mid+1;
        
        for(int i = start; i <= mid; i++){
            while(j<=end&&(sums[j]-sums[i])<=upper){
                j++;
            }
            while(k<=end&&(sums[k]-sums[i])<lower){
                k++;
            }
            result+=j-k;
        }
        
        merge(sums, start, end, temp);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1, 0);
        vector<long> temp(nums.size()+1, 0);
        for(int i = 1; i <= nums.size(); i++){
            sums[i] = sums[i-1] + nums[i-1];
        }
        int result = 0;
        mergeSort(sums, 0, sums.size()-1, temp, result, lower, upper);
        return result;
    }
};

int main() {
    return 0;
}