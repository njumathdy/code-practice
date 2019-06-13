/*******************
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. 
You win the game when you guess the number I picked.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

// based on dp
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (int k = j; k <= i; ++k){
                    int tmp = k + max(dp[j][k - 1], dp[k + 1][i]);
                    min_value = min(min_value, tmp);
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
    }
};

int main() {
    return 0;
}