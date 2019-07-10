/*******************
Given an array of scores that are non-negative integers. 
Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. 
Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. 
The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// recursive
class Solution1 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        return winner(nums, 0, nums.size()-1, 1) >= 0;
    }
    
    int winner(vector<int>& nums, int s, int e, int turn) {
        if(s == e)
            return turn * nums[s];
        int a = turn * nums[s] + winner(nums, s+1, e, -turn);
        int b = turn * nums[e] + winner(nums, s, e-1, -turn);
        
        return turn * max(turn * a, turn * b);
    }
};

// dp
class Solution2 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n, 0));
        
        for(int i = n; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                int a = nums[i] - dp[i+1][j];
                int b = nums[j] - dp[i][j-1];
                dp[i][j] = max(a, b);
            }
        }
        
        return dp[0][n-1] >= 0;
    } 
};

int main() {
    return 0;
}