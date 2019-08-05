/*******************
Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int res = 0;
        
        for(int i = 1; i < nums.size(); i += 2) {
            if(i == nums.size() - 1) {
                if(nums[i] >= nums[i-1])
                    res += nums[i] - nums[i-1] + 1;
            } else {
                if(nums[i] >= min(nums[i-1], nums[i+1]))
                    res += nums[i] - min(nums[i-1], nums[i+1]) + 1;
            }
        }
        
        int temp = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            if(i == nums.size() - 1) {
                if(nums[i] >= nums[i-1])
                    temp += nums[i] - nums[i-1] + 1;
            } else if(i == 0) {
                if(nums[i] >= nums[i+1])
                    temp += nums[i] - nums[i+1] + 1;
            } else {
                if(nums[i] >= min(nums[i-1], nums[i+1]))
                    temp += nums[i] - min(nums[i-1], nums[i+1]) + 1;
            }
        }
        
        return min(res, temp);
    }
};

int main() {
    return 0;
}