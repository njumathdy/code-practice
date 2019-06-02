/*******************
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
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
class Trie{
public:
    Trie* children[26]; // pointers to its substrings starting with 'a' to 'z'
    bool leaf; // if the node is a leaf, or if there is a word stopping at here
    int idx; // if it is a leaf, the string index of the array words
    Trie() {
        this->leaf = false;
        this->idx = 0;
        fill_n(this->children, 26, nullptr);            
    }
};
        
public:
    void insertWords(Trie* root, vector<string>& words, int idx) {
        int pos = 0, len = words[idx].size();
        while(pos < len) {
            if(root->children[words[idx][pos]-'a'] == nullptr) 
                root->children[words[idx][pos]-'a'] = new Trie();
            root = root->children[words[idx][pos++]-'a'];
        }
        root->leaf = true;
        root->idx = idx;
    }
        
    Trie* buildTrie(vector<string>& words) {
        Trie* root = new Trie(); 
        int i;
        for(i = 0; i < words.size();i++) 
            insertWords(root, words, i);
        return root;
    }
        
    void checkWords(vector<vector<char> >& board, int i, int j, int row, int col, Trie *root, vector<string> &res, vector<string>& words) {
        char temp;
        if(board[i][j]=='X') return; // visited before;
        if(root->children[board[i][j]-'a'] == nullptr) 
            return; // no string with such prefix
        else {
            temp = board[i][j];
            if(root->children[temp-'a']->leaf)  // if it is a leaf
            {
                res.push_back(words[root->children[temp-'a']->idx]);
                root->children[temp-'a']->leaf = false; // set to false to indicate that we found it already
            }
            board[i][j]='X'; //mark the current position as visited
            // check all the possible neighbors
            if(i>0) checkWords(board, i-1, j, row, col, root->children[temp-'a'], res, words);
            if((i+1)<row) checkWords(board, i+1, j, row, col,  root->children[temp-'a'], res, words);
            if(j>0) checkWords(board, i, j-1,  row, col, root->children[temp-'a'], res, words);
            if((j+1)<col)  checkWords(board, i, j+1,  row, col, root->children[temp-'a'], res, words);
            board[i][j] = temp; // recover the current position
        }
    }
    
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || board[0].empty() || words.empty())
            return res;
        
        int row = board.size(), col = board[0].size(), wordCount = words.size();
        Trie *root = buildTrie(words);
           
        int i,j;
        for(i = 0 ; i < row; i++) {
            for(j = 0; j < col && wordCount > res.size(); j++) {
                checkWords(board, i, j, row, col, root, res, words);
            }
        }
        return res;
    }
 };

int main() {
    return 0;
}