/*******************
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// dp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int i, j;
        for(i = 2; i <= n; i++) {
            for(j = 1; j <= i; j++) 
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }
};

int main() {
    return 0;
}