/******************
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// two pointers
class Solution1 {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        
        int i =0, j = 0;
        int match = 0, index = -1;
        while(i < n1) {
            // 字符匹配，下一个
            if(j < n2 && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            // p[j] = '*': 暂时忽略，当成空字符串
            } else if(j < n2 && p[j] == '*') {
                index = j;
                match = i;
                j++;
            // 当成一个字符串，此后每次遇到这个条件一次递加
            } else if(index != -1) {
                j = index+1;
                match++;
                i = match;
            // 字符不匹配，并且没有'*'，说明不匹配
            } else 
                return false;
        }
        while(j < n2 && p[j] == '*')
            j++;
        
        return j == n2;
    }
};

// dp
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        // cur[i]表示s[0, i)和p[0,j)s是否匹配
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // 更新前记录该值，用来帮助更新下一个值
            // cur[0]表示空字符串
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; 
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m];
    }
};

int main() {
    return 0;
}