/*******************
Write a program to solve a Sudoku puzzle by filling the empty cells.
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
    // 用来检查是否可行
    bool check(vector<vector<char> > &board, int i, int j, char val) {
        int row = i - i%3, column = j - j%3; // 判断i, j所在方格
        // 检查行
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        // 检查列
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        // 检查方格
        for(int x=0; x<3; x++)
            for(int y=0; y<3; y++)
                if(board[row+x][column+y] == val) return false;

        return true;
    }

    bool solveSudoku(vector<vector<char> > &board, int i, int j) {
        // 检查完所有行，没有问题
        if(i==9) return true;
        // 检查完该行的所有列，检查下一行
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);

        for(char c='1'; c<='9'; c++) {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        solveSudoku(board, 0, 0);
    }
};

int main() {
    return 0;
}