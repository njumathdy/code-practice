/*******************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// 动态规划，定义四个状态。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) 
            return 0;
    
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i = 0; i < prices.size(); i++) {
            release2 = max(release2, hold2 + prices[i]);
            hold2 = max(hold2, release1-prices[i]);
            release1 = max(release1, hold1+prices[i]);
            hold1 = max(hold1, -prices[i]);
        }

        return release2;
    }
};

int main() {
    return 0;
}