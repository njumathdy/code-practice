/*******************
 * 条件仍同前面，再加一个限制，每次卖完股票的第二天不能进行交易。
 * 同样是一个动态规划问题，不过状态更加复杂。
 * 考虑三个状态：
 * sell[i]: 在第i天之前以卖出结束的最大的利润
 * buy[i]: 在第i天之前以买入结束的最大的利润
 * rest[i]: 以第i天之前以do nothing结束的最大的利润
 * 递推关系：
 * buy[i] = max(rest[i-1]-price, buy[i-1])
 * sell[i] = max(buy[i-1]+price, sell[i-1])
 * rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
 * 可以进一步分析得到：
 * rest[i] = sell[i-1]
 * 将上面简化，有：
 * buy[i] = max(sell[i-2] - price, buy[i-1])
 * sell[i] = max(buy[i-1] + price, sell[i-1])
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <limits.h>
#include <algorithm>

using namespace std;

int MaxProfit(const int* prices, unsigned length) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;

    for(int i = 0; i < length; i++) {
        prev_buy = buy;
        buy = max(prev_sell-prices[i], buy);
        prev_sell = sell;
        sell = max(prev_buy+prices[i], sell);
    }

    return sell;
}

int main() {
    return 0;
}