/*******************
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <limits.h>
#include <unordered_map>

using namespace std;

// bfs
class Solution1 {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string> > paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            // 下一层
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                // 不是最短，直接剪枝
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};

// bidirectional bfs
class Solution2 {
public:
    //DFS 
    void buildLadders(string start, string end, unordered_map<string, vector<string> >& nexts, vector<string>& path, vector<vector<string>>& rs) {
        if (start == end) {
            rs.push_back(path);
            return;
        }
        
        for (auto &next : nexts[start]) {
            path.push_back(next);
            buildLadders(next, end, nexts, path, rs);
            path.pop_back();
        }
    }
    
    bool findLaddersHelper(unordered_set<string>& head, unordered_set<string>& tail, unordered_set<string>& wordBank, unordered_map<string, vector<string> >& nexts, bool flip) {
        if (head.empty()) {
            return false;
        }
        if (head.size() > tail.size()) {
            return findLaddersHelper(tail, head, wordBank, nexts, !flip);
        }
        
        for (const string &word : head) {
            wordBank.erase(word);
        }
        for (const string &word : tail) {
            wordBank.erase(word);
        }
        
        unordered_set<string> temp;
        bool done = false;
        for (string word : head) {
            string curr = word;
            for (int i = 0; i < curr.size(); i++) {
                string candidate = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    candidate[i] = c;
                    
                    if (tail.find(candidate) != tail.end()) {
                        done = true;
                        flip ? nexts[candidate].push_back(curr) : nexts[curr].push_back(candidate);
                    }
                    else if (!done && wordBank.find(candidate) != wordBank.end()) {
                        temp.insert(candidate);
                        flip ? nexts[candidate].push_back(curr) : nexts[curr].push_back(candidate);
                    }
                }
            }
        }
        
        return done || findLaddersHelper(tail, temp, wordBank, nexts, !flip);
    }
    
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordBank(wordList.begin(), wordList.end());
        if (wordBank.find(endWord) == wordBank.end()) {
            return {};
        }
        
        vector<vector<string> > rs;
        unordered_map<string, vector<string> > nexts;
        vector<string> path(1, beginWord);
        unordered_set<string> head, tail;
        
        head.insert(beginWord);
        
        tail.insert(endWord);
        
        if (findLaddersHelper(head, tail, wordBank, nexts, false)) {
            buildLadders(beginWord, endWord, nexts, path, rs);
        }
        
        return rs;
    }
};

int main() {
    return 0;
}