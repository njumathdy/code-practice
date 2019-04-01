/*******************
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() < 1) return false;
        int lo =0, hi = nums.size()-1;
        int mid = 0;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[hi]){
                if(nums[mid]>target && nums[lo] <= target) hi = mid;
                else lo = mid + 1;
            }else if(nums[mid] < nums[hi]){
                if(nums[mid]<target && nums[hi] >= target) lo = mid + 1;
                else hi = mid;
            }else{
                hi--;
            }
        }
        return nums[lo] == target;
    }
};

int main() {
    return 0;
}