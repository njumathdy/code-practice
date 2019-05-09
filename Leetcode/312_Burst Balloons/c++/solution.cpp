/*******************
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// dp & divide and conquer
// Leetcode solution
// 这道题我自己没有思考出来，看到提示中的dp 和 divide and conquer也没有具体的思路
// 解答的思路如下：
// 用dp[left][right]表示[left, right]之间的气球所能获得的最大金币数。
// 状态转移方程是：
// dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left-1][k-1] + dp[k+1][right])
// 写成上面的形式是因为前面的操作会影响到后面的操作，所以会改变后面碰到的状态，所以我们考虑的是最后一次选取的气球，
// 后面的状态显然不会影响前面的状态，所以可以将问题分解为子问题进行求解。
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        return dp[1][n];
    }
};

int main() {
    return 0;
}