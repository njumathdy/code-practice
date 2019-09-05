/*******************
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
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
    int islandPerimeter(vector<vector<int> >& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    continue;
                int count = 0;
                for(int k = 0; k < 4; k++) {
                    if(i + x[k] < 0 || i + x[k] >= m || j + y[k] < 0 || j + y[k] >= n)
                        continue;
                    if(grid[i+x[k]][j+y[k]] == 1)
                        count++;
                }
                res += (4 - count);
            }   
        }
        
        return res;
    }
};

int main() {
    return 0;
}