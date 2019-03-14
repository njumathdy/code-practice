/*******************
 * 同上一道题，不过条件放宽成可以进行多次交易。
 * 本题思路也比较清晰，只要求连续的递增序列的首尾之差即可。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>

using namespace std;

int MaxProfit(const int* numbers, unsigned length) {
    if(numbers == nullptr || length < 2) 
        return 0;

    int maxProfit = 0;
    for(int i = 1; i < length; i++) {
        if(numbers[i] > numbers[i-1]) 
            maxProfit += (numbers[i] - numbers[i-1]); // 该实现并不意味着在同一天内买入卖出，相当于对减法做了加括号的变换。
    }

    return maxProfit;
}

int main() {
    return 0;
}