/*******************
A 2d grid map of m rows and n columns is initially filled with water. 
We may perform an addLand operation which turns the water at position (row, col) into a land. 
Given a list of positions to operate, count the number of islands after each addLand operation. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
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

class UnionFind{
private:
    vector<int> parent;
    vector<int> weight;
    int count;

public:
    UnionFind(int N){
        parent = vector<int> (N, -1);
        weight = vector<int> (N, 0);
        count = 0;
    }

    bool isValid(int i){
        return parent[i] >= 0;
    }

    void SetParent(int i){
        parent[i] = i;
        count++;
    }

    int find(int i){
        if (parent[i]!=i){
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);

        if (rootx != rooty){
            if (weight[rootx] >= weight[rooty]){
                parent[rooty] = rootx;
                weight[rootx] += weight[rooty];
            }
            else{
                parent[rootx] = rooty;
                weight[rooty] += weight[rootx];
            }
            count--;
        }
    }

    int getCount(){
        return count;
    }

};

class Solution {
public:    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result;
        UnionFind uf(m*n);

        for (auto pos : positions){

            int x0 = pos.first;
            int y0 = pos.second;

            int cell0 = x0*n+y0;
            uf.SetParent(cell0);

            vector<int> dx = {1, 0, -1, 0};
            vector<int> dy = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++){
                int x1 = x0 + dx[i];
                int y1 = y0 + dy[i];

                int cell1 = x1*n + y1;

                if (x1 >=0 && x1 < m && y1 >= 0 && y1 < n && uf.isValid(cell1)){
                    uf.Union(cell1, cell0);
                }   
            }

            result.push_back(uf.getCount());
        }

        return result;       
    }
};

int main() {
    return 0;
}