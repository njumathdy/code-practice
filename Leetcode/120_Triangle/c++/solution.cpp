/*******************
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划，bottom-up
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.size() < 1)
            return 0;
        
        int n = triangle.size();
        // 直接用triangle初始化dp
        vector<int> dp(triangle.back().begin(), triangle.back().end());
        
        for(int i = n-2; i >= 0; i--)
            for(int k = 0; k <= i; k++)
                dp[k] = min(dp[k], dp[k+1]) + triangle[i][k];
        
        return dp[0];
    }
};

int main() {
    return 0;
}