/*******************
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        int start = 0, end = nums.size() - 1;
        int middle;
        while(start < end) {
            middle = start + (end - start) / 2;
            if((middle == 0 && nums[middle] > nums[middle+1]) || (middle == nums.size()-1 && nums[middle] > nums[middle-1]))
               return middle;
            if(nums[middle] > nums[middle+1] && nums[middle] > nums[middle-1])
               return middle;
            if(nums[middle] < nums[middle+1]) {
                start = middle + 1;
            } else
                end = middle - 1;
        }
        return start;
    }
};

int main() {
    return 0;
}