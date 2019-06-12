/*******************
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
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
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0;i < dp.size();i++)
            for(int j = 0;j < nums.size();j++)
                if(nums[j] <= i)
                    dp[i] += dp[i - nums[j]];
        return dp[target];
    } 
};

int main() {
    return 0;
}