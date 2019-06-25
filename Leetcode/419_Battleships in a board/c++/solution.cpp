/*******************
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
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
    int countBattleships(vector<vector<char> >& board) {
        if(board.empty() || board[0].empty())
            return 0;
        
        int m = board.size(), n = board[0].size();
        int res = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                res += board[i][j] == 'X' && (i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X');
        
        return res;
    }
};

int main() {
    return 0;
}