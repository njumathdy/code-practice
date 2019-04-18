/*******************
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
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

// dp: dp[i][j]表示s[0,i)和p[0,j)是否匹配
// dp[i][j] = dp[i-1]dp[j-1] && s[i-1] == p[j-1], if p[j-1] != '*';
// dp[i][j] = dp[i][j-2], if p[j-1] == '*'且重复0次
// dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j-1] == '*'并且至少重复一次

// O(mn)space
class Solution1 {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=0; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j - 2] || 
                        (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[m][n];  
    }
};

// O(n)space
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> cur(n + 1, false);
        for (int i = 0; i <= m; i++) {
            bool pre = cur[0];
            cur[0] = !i;
            for (int j = 1; j <= n; j++) {
                bool temp = cur[j];
                if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};

int main() {
    return 0;
}