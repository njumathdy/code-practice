/*******************
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.
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
    int longestPalindromeSubseq(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int len = 0;
            for (int j = i - 1; j >= 0; j--) {
                int tmp = dp[j];
                if (s[j] == s[i]) {
                    dp[j] = len + 2;
                }
                len = max(len, tmp);
            }
        }
        for (auto i : dp)
            res = max(res, i);
        return res;
    }
};

class Solution2 {
public:
    int longestPalindromeSubseq(string s)
    {
        int dp[s.length()][s.length()];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            }
        }
        return dp[s.length() - 1][0];    
    }
};

int main() {
    return 0;
}