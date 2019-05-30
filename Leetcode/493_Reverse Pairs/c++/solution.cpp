/*******************
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// based on binary indexed tree
class Solution1 {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int n = nums.size();
        vector<int> nums_copy(nums);
        
        sort(nums_copy.begin(), nums_copy.end());
        
        // suffix sum
        vector<int> BITS(n+1, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
            update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
        }
        
        return count;
    }
    
    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {
            BIT[index] += val;
            index -= index & (-index);
        }
    }
    
    // gives the suffix sum
    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }
};

// based on merge sort
class Solution2 {
public:
    void merge(vector<int>& A, int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;
        vector<int> L(n1, 0), R(n2, 0);
        for(int i = 0; i < n1; i++)
            L[i] = A[start+i];
        for(int j = 0; j < n2; j++)
            R[j] = A[mid+1+j];
        int i = 0, j = 0;
        for(int k = start; k <= end; k++) {
            if(j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }
    
    int mergesort_and_count(vector<int>& A, int start, int end) {
        if(start < end) {
            int mid = start + (end - start) / 2;
            int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid+1, end);
            int j = mid + 1;
            for(int i = start; i <= mid; i++) {
                while(j <= end && A[i] > A[j] * 2LL)
                    j++;
                count += j - mid - 1;
            }
            merge(A, start, mid, end);
            return count;
        } else
            return 0;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergesort_and_count(nums, 0, nums.size() - 1);
    }   
};

int main() {
    return 0;
}