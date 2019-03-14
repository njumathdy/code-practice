/*******************
 * 将股票价格按顺序存储在数组中，买卖股票一次可能获得的最大利润。
 * 剑指offer。
 * 思路十分清晰，定义一个函数diff(i)为卖出价为数组中第i个数字时可能获得的最大利润。
 * 扫描到i时，只需记住前i-1个数字中的最小值即可。我们只需扫描数组一遍既能得到答案。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>

int MaxProfit(const int* numbers, unsigned length) {
    if(numbers == nullptr || length < 2) 
        return 0;

    int min = numbers[0];
    int maxProfit = numbers[1] - min;

    for(int i = 2; i < length; i++) {
        if(numbers[i-1] < min)
            min = numbers[i-1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxProfit)
            maxProfit = currentDiff;
    }

    return maxProfit;
}

using namespace std;

int main() {
    return 0;
}