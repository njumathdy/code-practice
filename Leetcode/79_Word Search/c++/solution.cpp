/*******************
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty())
            return false;
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(dfs(board, word, m, n, i, j, 0))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char> >& board, string& s, int m, int n, int i, int j, int index) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != s[index])
            return false;
        if(index == s.length()-1)
            return true;
        
        char cur = board[i][j];
        board[i][j] = '*'; // 通过将该值设为一个特殊的值表明该位置已被搜索过
        bool res = dfs(board, s, m, n, i-1, j, index+1) ||
                   dfs(board, s, m, n, i+1, j, index+1) ||
                   dfs(board, s, m, n, i, j-1, index+1) ||
                   dfs(board, s, m, n, i, j+1, index+1);
        board[i][j] = cur; // 回溯，恢复原来的值
        return res;
    }
};

int main() {
    return 0;
}