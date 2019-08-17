/*******************
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for(auto w : words) {
            int n = w.size();
            vector<int> dp(n+1);
            dp[0] = 1;
            for(int i = 0; i < n; i++) {
                if(dp[i] == 0)
                    continue;
                for(int j = i+1; j <= n; j++) {
                    if(j - i < n && s.count(w.substr(i, j-i)))
                        dp[j] = 1;
                }
                if(dp[n]) {
                    res.push_back(w);
                    break;
                }
            }
        }
        
        return res;
    }
};

class Solution2 {
private:
    struct TrieNode {
        vector<TrieNode*> sons;
        bool isEnd = false;
        
        TrieNode() {
            sons.resize(26);
        }     
    };
   
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.empty())
            return {};
        
        vector<string> res;
        TrieNode* root = new TrieNode();
        for(auto word : words) {
            if(word.empty())
                continue;
            addWord(word, root);
        }
        
        for(auto word : words) {
            if(word.empty())
                continue;
            if(testWord(word, 0, root, 0))
                res.push_back(word);
        }
        return res;
    }
    
    bool testWord(string s, int index, TrieNode* root, int count) {
        TrieNode* cur = root;
        int n = s.size();
        for(int i = index; i < n; i++) {
            if(cur -> sons[s[i] - 'a'] == nullptr)
                return false;
            if((cur -> sons[s[i] - 'a']) -> isEnd) {
                if(i == n-1)
                    return count >= 1;
                if(testWord(s, i+1, root, count+1))
                    return true;
            }
            cur = cur -> sons[s[i] - 'a'];
        }
        return false;
    }
    
    void addWord(string s, TrieNode* root) {
        TrieNode* cur = root;
        for(auto c : s) {
            if(cur -> sons[c-'a'] == nullptr)
                cur -> sons[c-'a'] = new TrieNode();
            cur = cur -> sons[c - 'a'];
        }
        cur -> isEnd = true;
    }
};

int main() {
    return 0;
}