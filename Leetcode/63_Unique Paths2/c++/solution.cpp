/*******************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

// 简单的动态规划
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if(obstacleGrid.size() < 1 || obstacleGrid[0].size() < 1)
            return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;

        vector<vector<long> > dp(m, vector<long> (n, 0));
        
        dp[0][0] = 1;
        int i = 1, j = 1;
        // 一开始while这里两个条件顺序有误，导致数组访问总会越界。
        while(i < m && obstacleGrid[i][0] != 1) {
            dp[i][0] = 1;
            i++;
        }
        while(j < n && obstacleGrid[0][j] != 1) {
            dp[0][j] = 1;
            j++;
        }
        for(i = 1; i < m; i++) {
            for(j = 1; j < n; j++) {
                if(!obstacleGrid[i][j])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];       
    }
};

int main() {
    return 0;
}