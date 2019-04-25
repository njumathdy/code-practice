/*******************
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
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
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        
        int i, j;
        int ans = 0;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(grid[i][j] == '0' || grid[i][j] == '2')
                    continue;
                else {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        } 
        return ans;
    }
    
    void dfs(vector<vector<char> >&grid, int i, int j, int m, int n) {
        if(grid[i][j] == '0' || grid[i][j] == '2')
            return;
            
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        grid[i][j] = '2';
        for(int k = 0; k < 4; k++) {
            if(i+dx[k] < 0 || i+dx[k] >= m || j+dy[k] < 0 || j+dy[k] >= n)
                continue;
            if(grid[i+dx[k]][j+dy[k]] == '1') 
                dfs(grid, i+dx[k], j+dy[k], m, n);
        }
    }
};

int main() {
    return 0;
}