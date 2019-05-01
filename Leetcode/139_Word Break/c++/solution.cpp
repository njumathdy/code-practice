/*******************
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

// dp
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0)
            return false;
        
        int n = s.size();
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(dp[j]) {
                    if(dict.find(s.substr(j, i-j)) != dict.end()) {
                        dp[i] = true;
                        break;
                    }        
                }
            }
        }
        
        return dp[n];
    }
};

// bfs: Leetcode solution
class Solution2 {
public: 
    bool wordBreak(string s, unordered_set<string> &dict) {
    // BFS
        queue<int> BFS;
        unordered_set<int> visited;
    
        BFS.push(0);
        while(BFS.size() > 0) {
            int start = BFS.front();
            BFS.pop();
            if(visited.find(start) == visited.end()) {
                visited.insert(start);
                for(int j=start; j<s.size(); j++)
                {
                    string word(s, start, j-start+1);
                    if(dict.find(word) != dict.end())
                    {
                        BFS.push(j+1);
                        if(j+1 == s.size())
                            return true;
                    }
                }
            }
        }
    
        return false;
    }
};

int main() {
    return 0;
}