/*******************
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

// my solution: dp
class Solution1 {
public:
    int numSquares(int n) {
        if(n == 0)
            return 0;
        
        vector<int> dp(n+1, n);
        dp[1] = 1, dp[0] = 0;
        int i, j = 1;
        for(i = 2; i < n+1; i++) {
            while(j * j <= i) 
                j++;
            j--;
            for(; j > 0; j--) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        
        return dp[n];
    }   
};

// Leetcode solution
class Solution2 {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};

int main() {
    return 0;
}