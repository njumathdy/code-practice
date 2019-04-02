/*******************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[i] > prices[i+1])
                continue;
            else
                ans += prices[i+1] - prices[i];   
        }
        return ans;     
    }
};

int main() {
    return 0;
}