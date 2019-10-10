/*******************
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
After, what is the size of the largest island? 
(An island is a 4-directionally connected group of 1s).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int index = 2, res = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        unordered_map<int, int> area;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    area[index] = dfs(grid, i, j, index);
                    res = max(res, area[index++]);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s;
                    int cur = 1;
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if(x < 0 || x >= m || y < 0 || y >= n) continue;
                        if(grid[x][y] > 1 && s.count(grid[x][y]) == 0) {
                            s.insert(grid[x][y]);
                            cur += area[grid[x][y]];
                        }
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int> >& grid, int i, int j, int index) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int area = 0;
        grid[i][j] = index;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
                continue;
            area += dfs(grid, x, y, index);
        }
        return area + 1;
    }
};

int main() {
    return 0;
}