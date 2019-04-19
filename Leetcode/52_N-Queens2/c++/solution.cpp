/*******************
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
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
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n, ans);
        
        return ans;
    }
    
    void dfs(vector<string>& board, int row, int n, int& ans) {
        int i;
        if(row == n)
            ans++;
        else {
            for(i = 0; i < n; i++) {
                board[row][i] = 'Q';
                if(check(board, row, i, n))
                    dfs(board, row+1, n, ans);
                board[row][i] = '.';
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