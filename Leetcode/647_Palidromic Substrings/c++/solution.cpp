/*******************
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
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
    int countSubstrings(string s) {
        if(s.size() < 2)
            return s.size();
        
        int n = s.size(), res = 0;
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for(int k = 1; k <= n - 1; k++) {
            for(int i = 0; i < n; i++) {
                if(i + k >= n)
                    continue;
                if(k == 1)
                    dp[i][i+k] = s[i] == s[i+k];
                else
                    dp[i][i+k] = (s[i] == s[i+k] && dp[i+1][i+k-1]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
};

class Solution2 {
 public:
	 int countSubstrings(string s) {
		 int N = s.length();
		 int result = 0;
		 for (int center = 0; center <= 2*N-1; center++)
		 {
			 int left = center / 2;
			 int right = left + center % 2;
			 //当center为回文中心时，往两边扩展，若还是回文则结果++
			 while (left >= 0 && right < N && s.at(left) == s.at(right))
			 {
				 result++;
				 left--;
				 right++;
			 }
		 }
		 return result;
	 }
 };

int main() {
    return 0;
}