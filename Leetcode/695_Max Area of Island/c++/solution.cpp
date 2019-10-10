/*******************
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
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
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int tmp = 0;
                    dfs(grid, i, j, tmp);
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int> >& grid, int i, int j, int& tmp) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        tmp++;
        grid[i][j] = 0;
        int m = grid.size(), n = grid[0].size();
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(x < 0 || x >=m || y < 0 || y >= n || grid[x][y] != 1) continue;
            dfs(grid, x, y, tmp);
        }
    }
};

int main() {
    return 0;
}