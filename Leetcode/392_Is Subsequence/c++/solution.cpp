/*******************
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

// greedy
class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;
        if(t.empty())
            return false;
        
        map<int, int> dict;
        dict[-1] = 0;
        for(int i = 0; i < s.size(); i++) {
            string temp = t.substr(dict[i-1]);
            if(temp.find(s[i]) == string::npos)
                return false;
            else
                dict[i] = temp.find(s[i]) + dict[i-1] + 1;
        }
        
        return true;
    }
};

class Solution2 {
public:
    bool isSubsequence(string s, string t) {  
        int m = s.size();
        int n = t.size();
        if(m==0) return true;
        if(n==0) return false;
        bool poss = false;
        int i = 0, j = 0;
        while(1)
        {   
            if(s[i] == t[j])
            {
                i++;
                j++;
                if(i == m) return true;
                if(j == n) return false;
            }
            else
            {
                while(s[i] != t[j]){    j++; if(j == n) return false; }
            }
        }
        
        return poss;
    }    
};

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. 
// In this scenario, how would you change your code?
class Solution3 {
public: 
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;
        if(t.empty())
            return false;

        map<char, vector<int> > table;
        for(int i = 0; i < t.size(); i++) {
            if(table.find(t[i]) == table.end()) 
                table[t[i]] = {i};
            else 
                table[t[i]].push_back(i);
        }

        int prev = -1;
        for(int i = 0; i < s.size(); i++) {
            if(table.find(s[i]) == table.end())
                return false;
            else {
                vector<int> temp = table[s[i]];
                auto iter = lower_bound(temp.begin(), temp.end(), prev);
                if(iter == temp.end())
                    return false;
                else 
                    prev = ++(*iter);
            }
        }

        return true;
    }
};

int main() {
    return 0;
}