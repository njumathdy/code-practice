/*******************
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distince solutions to the n-queens puzzle.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// backtracking
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string> > ans;
        dfs(ans, temp, 0, n);
        
        return ans;    
    }
    
    void dfs(vector<vector<string> >& ans, vector<string>& temp, int k, int n) {
        int i;
        if(k == n) 
            ans.push_back(temp);
        else {
            for(i = 0; i < n; i++) {
                temp[k][i] = 'Q';
                if(check(temp, k, i, n)) 
                    dfs(ans, temp, k+1, n);
                temp[k][i] = '.';
            }
        }
    }
    
    bool check(vector<string>& temp, int row, int col, int n) {
        int i, j;
        for(i = 0; i < row; i++) {
            if(temp[i][col] == 'Q')
                return false;
        }
        
        i = row - 1, j = col - 1;
        while(i >= 0 && j >= 0) {
            if(temp[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = row - 1, j = col + 1;
        while(i >= 0 && j < n) {
            if(temp[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        
        return true;
    }
};

int main() {
    return 0;
}