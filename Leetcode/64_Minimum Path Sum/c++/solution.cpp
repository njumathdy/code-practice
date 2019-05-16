/*******************
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// simple dp
class Solution1 {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        int i, j;
        for(i = 1; i < m; i++) 
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        
        for(i = 1; i < m; i++) {
            for(j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};

// O(n) space
class Solution2 {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        
        int i, j;
        for(i = 1; i < n; i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        
        for(i = 1; i < m; i++) {
            dp[0] = dp[0] + grid[i][0];
            for(j = 1; j < n; j++) 
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
        
        return dp[n-1];    
    }
};

int main() {
    return 0;
}