/*******************
 * 条件同前面两题，只不过要求至多只能完成两次交易。
 * 动态规划。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <limits.h>
#include <algorithm>

using namespace std;

int MaxProfit(const int* numbers, unsigned length) {
    if(numbers == nullptr || length < 2) 
        return 0;
    
    // 定义四个状态：第一次买入股票之后的最大值、第一次卖出之后的最大值、第二次买入之后的最大值以及第二次卖出之后的最大值。
    int hold1 = INT_MIN, hold2 = INT_MIN;
    int release1 = 0, release2 = 0;
    for(int i = 0; i < length; i++) {
        release2 = max(release2, hold2 + numbers[i]);
        hold2 = max(hold2, release1-numbers[i]);
        release1 = max(release1, hold1+numbers[i]);
        hold1 = max(hold1, -numbers[i]);
    }

    return release2;
}

int main() {
    return 0;
}