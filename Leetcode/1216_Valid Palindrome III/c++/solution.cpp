/*******************
Given a string s and an integer k, find out if the given string is a K-Palindrome or not.
A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.
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
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
        for (int i = 0; i < s.length(); i++)
            dp[i][i] = 1;

        for (int len = 1; len <= s.length(); len++) {
            for (int i = 0; i + len < s.length(); i++) {
                int j = i + len;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][s.length() - 1];
    }
    
    bool isValidPalindrome(string s, int k) {
        if(s.empty()) return true;
        int l = s.size() - longestPalindromeSubseq(s);
        return l <= k;
    }  
};

int main() {
    return 0;
}