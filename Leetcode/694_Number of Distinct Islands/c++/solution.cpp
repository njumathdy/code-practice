/*******************
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public: 
    int numDistinctIslands(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        set<vector<vector<int> > > s;
        vector<vector<int> > path;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    path.clear();
                    dfs(grid, i, j, path, s);
                    int x = path[0][0], y = path[0][1];
                    for(int k = 0; k < path.size(); k++) {
                        path[k][0] -= x;
                        path[k][1] -= y;
                    }
                    s.insert(path);
                }
            }
        }

        return s.size();
    }

    void dfs(vector<vector<int> >& grid, int i, int j, vector<vector<int> >& path, set<vector<vector<int> > >& s) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        path.push_back({i, j});
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) continue;
            dfs(grid, x, y, path, s);
        }
    }
};

int main() {
    return 0;
}