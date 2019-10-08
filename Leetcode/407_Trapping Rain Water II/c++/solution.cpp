/*******************
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        int res = 0, h = INT_MIN;
        vector<vector<int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    q.push({heightMap[i][j], i*n + j});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            auto t = q.top();
            q.pop();
            h = max(h, t.first);
            int r = t.second / n, c = t.second % n;
            for(int i = 0; i < 4; i++) {
                int x = r + dir[i][0], y = c + dir[i][1];
                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if(heightMap[x][y] < h) res += h - heightMap[x][y];
                q.push({heightMap[x][y], x*n + y});
            }
        }
        
        return res;
    }
};

int main() {
    return 0;
}