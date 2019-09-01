/*******************
仍n个骰子，第i个骰子有可能投掷出Xi中等概率的不同的结果，数字从1到Xi。
所有骰子的结果的最大值将作为最终结果。求最终结果的期望。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
 
long long C[51][51] = {0};

// 组合数
void GetC(int maxn)
{
    C[0][0] = 1;
    for(int i = 1; i <= maxn; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
}

double getNum(const int *arr, const int n, const int maxNum) {
    int gE = 0;
    double less = 1.0;
    double ret = 0.0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] >= maxNum) gE++;
        else less *= arr[i];
    }
    for(int k = 1; k <= gE; ++k) {
        double cn = C[gE][k]; // 选k个，使得其点数为maxNum
        double tP = 1.0;
        for(int i = 0; i < gE - k; ++i) {
            tP = tP * (maxNum - 1);
        }
        ret = ret + cn * tP * less; // 全部的个数
    }
    return ret;
}

int main(){
    int n = 0;
    int maxNum = 0;
    double fenmu = 1.0;
    double fenzi = 1.0;
    double ans = 1.0;
    int arr[55] = {0};
    cin >> n;
    GetC(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        fenmu *= arr[i];
        if(arr[i] > maxNum) maxNum = arr[i];
    }
    for(int i = 2; i <= maxNum; ++i) {
        fenzi = fenzi + i * getNum(arr, n, i);
    }
    ans = fenzi/fenmu;
    printf("%.2lf\n", ans);
    return 0;
}

