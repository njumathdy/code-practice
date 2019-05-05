/*******************
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// dfs
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(nums, 0, S, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int i, long long target, int& res) {
        if(i == nums.size()) {
            if(target == 0)
                res++;
            return;
        }
        dfs(nums, i+1, target - nums[i], res);
        dfs(nums, i+1, target + nums[i], res);
    }
};

// dp
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num: nums){
            sum += num;
        }
        
        if (S-sum >0 || S + sum < 0 || (S+sum)%2 == 1) return 0;
        int target = (S+sum)/2;
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(auto num : nums){
            for (int i = target; i>= num; i--){
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};

int main() {
    return 0;
}