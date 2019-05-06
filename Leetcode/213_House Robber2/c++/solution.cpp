/*******************
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
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
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() < 4)
            return *max_element(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dp1(n-1, 0);
        vector<int> dp2(n-1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i = 2; i < n-1; i++) {
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        for(int i = 2; i < n-1; i++)
            dp2[i] = max(dp2[i-2] + nums[i+1], dp2[i-1]);
        
        return max(dp1[n-2], dp2[n-2]);
    }
};

int main() {
    return 0;
}