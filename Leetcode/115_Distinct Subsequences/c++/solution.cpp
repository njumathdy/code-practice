/*******************
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size())
            return 0;
        
        int m = s.size(), n = t.size();
        
        vector<vector<long long> > dp(m+1, vector<long long>(n+1, 0));
        
        int i, j;
        for(i = 0; i <= m; i++)
            dp[i][0] = 1;
        for(i = 1; i <= m; i++) {
            for(j = 1; j <= n; j++) {
                if(t[j-1] != s[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        
        return dp[m][n];
    }
};

class Solution2 {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size())
            return 0;
        
        int m = s.size(), n = t.size();
        
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        
        int i, j;
        for(i = 1; i <= m; i++) {
            int prev = 1;
            for(j = 1; j <= n; j++) {
                int temp = dp[j];
                if(s[i-1] == t[j-1]) 
                    dp[j] += prev;
                
                prev = temp;
            }
        }
        
        return dp[n];
    }
};

int main() {
    return 0;
}