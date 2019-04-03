/*******************
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int release[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            release[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                release[j] = max(release[j],hold[j] + cur);
                hold[j] = max(hold[j],release[j-1] - cur);
            }
        }
        return release[k]; 
    }
};

int main() {
    return 0;
}