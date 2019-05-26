/*******************
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
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
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, dp, i, j, m, n));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j, int m, int n) {
        if(dp[i][j] > 0)
            return dp[i][j];
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        int path = 1;
        for(int k = 0; k < 4; k++) {
            if(i + dx[k] < 0 || i + dx[k] >= m || j + dy[k] < 0 || j + dy[k] >= n)
                continue;
            else {
                if(matrix[i][j] > matrix[i+dx[k]][j+dy[k]]) 
                    path = max(path, 1 + dfs(matrix, dp, i+dx[k], j+dy[k], m, n));
            }
        }
        dp[i][j] = path;
        return path;
   

int main() {
    return 0;
}