/*******************
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
*******************/
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 简单的dp，需要注意一些边界情况，即数字为0的位置
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < n; i++) {
            int temp = (s[i] - '0') + (s[i-1] - '0') * 10;
            if(s[i] == '0') {
                if(temp > 26 || temp == 0)
                    dp[i+1] = 0;
                else
                    dp[i+1] = dp[i-1];
            } else {
                if(temp > 10 && temp < 27)
                    dp[i+1] = dp[i] + dp[i-1];
                else
                    dp[i+1] = dp[i];
            }
        }
        
        return dp[n];
    }
};

int main() {
    return 0;
}