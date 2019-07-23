/*******************
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// recursion with memorization
class Solution1 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int> > memo(s1.size(), vector<int>(s2.size(), -1));
        return is_interleave(s1, 0, s2, 0, s3, 0, memo);
    }
    
    bool is_interleave(string s1, int i, string s2, int j, string s3, int k, vector<vector<int> >& memo) {
        if(i == s1.size())
            return s2.substr(j) == s3.substr(k);
        if(j == s2.size())
            return s1.substr(i) == s3.substr(k);
        
        if(memo[i][j] >= 0)
            return memo[i][j] == 1 ? true : false;
        
        bool ans = false;
        if((s3[k] == s1[i] && is_interleave(s1, i+1, s2, j, s3, k+1, memo)) || (s3[k] == s2[j] && is_interleave(s1, i, s2, j+1, s3, k+1, memo))) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};

// 2D dp
class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        for(int i = 0; i <= s1.size(); i++) {
            for(int j = 0; j <= s2.size(); j++) {
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                } else if(j == 0) {
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                } else {
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main() {
    return 0;
}