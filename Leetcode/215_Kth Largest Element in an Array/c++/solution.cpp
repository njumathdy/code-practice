/*******************
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

// partition
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int left = 0, right = n - 1, target;
        while(true) {
            int p = partition(nums, left, right);
            if(p == k-1) {
                target = nums[p];
                break;
            }   
            else if(p > k - 1)
                right = p - 1;
            else
                left = p + 1;
        }
        return target;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l] >= pivot)
                l++;
            if(nums[r] <= pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

// min-heap based on priority_queue
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// max-heap based on priority_queue
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    return 0;
}