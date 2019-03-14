/*******************
 * 同前面，最多可以进行k次交易。
 * 动态规划，递推公式为：
 * dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

int MaxProfit(const int* prices, unsigned length, int numbers) {
    if(prices == nullptr || length < 2)
        return 0;

    vector<vector<int> > dp(numbers+1, vector<int>(length, 0));

    for(int k = 1; k <= numbers; k++) {
        int minimum = prices[0];
        for(int i = 1; i < length; i++) {
            minimum = min(minimum, prices[i] - dp[k-1][i-1]);
            dp[k][i] = max(dp[k][i-1], prices[i] - minimum);
        }
    }

    return dp[numbers][length-1];   
}

int main() {
    return 0;
}