/*******************
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        if(amount == 0)
            return 0;
        if(amount < coins[0])
            return -1;
        
        int i;
        dp[0] = 0;
        for(i = 1; i < coins[0]; i++)
            dp[i] = -1;
        for(auto num : coins) {
            if(num <= amount)
                dp[num] = 1;
        }
        for(i = 1; i <= amount; i++) {
            for(auto num : coins) {
                if(i - num < 0)
                    break;
                if(dp[i - num] == -1)
                    continue;
                else
                    dp[i] = min(dp[i], 1 + dp[i - num]);
            }
            if(dp[i] == INT_MAX)
                dp[i] = -1;
        }
        return dp[amount];
    }
};

int main() {
    return 0;
}