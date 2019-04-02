/*******************
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() <= 1)
            return ans;
        
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] >= min) {
                ans = max(ans, prices[i] - min);
            } else
                min = prices[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}