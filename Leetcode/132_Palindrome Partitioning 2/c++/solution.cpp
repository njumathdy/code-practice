/*******************
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
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
    int minCut(string s) {
        if(s.size() < 2)
            return 0;
        
        int n = s.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; i++) {
            if(isPalindrome(s, 0, i))
                dp[i] = 0; 
            for(int j = 1; j <= i; j++) {
                if(isPalindrome(s, j, i)) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        
        return dp[n-1];
    }
    
    bool isPalindrome(const string s, int start, int end) {
        if(start > end)
            return false;
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    int minCut(string s) {
        if(s.size() < 2)
            return 0;
        
        int n = s.size();
        vector<int> cut(n, n);
        vector<vector<bool> > pal(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) {
            int minc = i;
            for(int j = 0; j <= i; j++) {
                if(s[j] == s[i] && (j+1 > i-1 || pal[j+1][i-1])) {
                    pal[j][i] = true;
                    minc = j == 0 ? 0 : min(minc, cut[j-1] + 1);
                }
            }
            cut[i] = minc;
        }
        
        return cut[n-1];
    }    
};

int main() {
    return 0;
}