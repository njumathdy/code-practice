/*******************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
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
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int n = prices.size();
        vector<int> sell(n, 0), rest(n, 0), buy(n, INT_MIN);
        buy[0] = -prices[0];
        
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], rest[i-1]-prices[i]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
            rest[i] = sell[i-1];
        }
        
        return sell[n-1];
    }
};

int main() {
    return 0;
}