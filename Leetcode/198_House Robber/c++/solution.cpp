/*******************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

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

// dp
class Solution1 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        
        return dp[n-1];
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        int a, b;
        a = nums[0];
        b = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++) {
            int temp = b;
            b = max(a + nums[i], b);
            a = temp;
        }
        
        return b;
    }
};

int main() {
    return 0;
}