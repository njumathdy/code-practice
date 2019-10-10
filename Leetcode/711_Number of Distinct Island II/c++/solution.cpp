/*******************
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.Count the number of distinct islands. 
An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).
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
    int numDistinctIslands2(vector<vector<int> >& grid) {
        int row_num = grid.size(), col_num = grid[0].size();
        set<vector<pair<int, int> > > islands;
        for (int r = 0; r < row_num; ++r) {
            for (int c = 0; c < col_num; ++c) {
                if (grid[r][c] == 1) {
                    vector<pair<int, int> > island;
                    DFS(grid, r, c, r, c, island);
                    islands.insert(normalize(island));
                }
            }
        }
        return islands.size();
    }
private:
    void DFS(vector<vector<int> > &grid, int r0, int c0, int r, int c, vector<pair<int, int>> &island) {
        int row_num = grid.size(), col_num = grid[0].size();
        if (r < 0 || r >= row_num || c < 0 || c >= col_num || grid[r][c] <= 0) {
            return;
        }
        grid[r][c] = -1;
        island.push_back(make_pair(r - r0, c - c0));
        for (int d = 0; d < 4; ++d) {
            DFS(grid, r0, c0, r + delta[d][0], c + delta[d][1], island);
        }
    }
    vector<pair<int, int> > normalize(vector<pair<int, int> > &a) {
        vector<vector<pair<int, int> > > ret(8, vector<pair<int, int> >());
        for (auto &p : a) {
            int x = p.first, y = p.second;
            ret[0].push_back(make_pair(x, y));
            ret[1].push_back(make_pair(x, -y));
            ret[2].push_back(make_pair(-x, y));
            ret[3].push_back(make_pair(-x, -y));
            ret[4].push_back(make_pair(y, x));
            ret[5].push_back(make_pair(y, -x));
            ret[6].push_back(make_pair(-y, x));
            ret[7].push_back(make_pair(-y, -x));
        }
        for (int i = 0; i < 8; ++i) {
            sort(ret[i].begin(), ret[i].end());
            int r_offset = 0 - ret[i][0].first, c_offset = 0 - ret[i][0].second;
            for (int j = 0; j < ret[i].size(); ++j) {
                ret[i][j].first += r_offset;
                ret[i][j].second += c_offset;
            }
        }
        sort(ret.begin(), ret.end());
        return ret[0];
    } 

private:  
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {
    return 0;
}