/*******************
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.
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
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3)
            return 0;
        if(n == 3)
            return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = n-1;
            
            while(k > j) {
                int temp = nums[i] + nums[j] + nums[k];
                if(temp == target)
                    return target;
                else {
                    ans = abs(target-ans) > abs(target-temp) ? temp : ans;
                    if(temp < target)
                        j++;
                    else
                        k--;
                }
            }   
        }
        return ans;
    }
};

int main() {
    return 0;
}