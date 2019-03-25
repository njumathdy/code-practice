/*
ID: mg172101
LANG: C++11
PROG: subset
*/

/*****************************
 * Given N, your program should print the number of ways a set containing the integers from 1 through N 
 * can be partitioned into two sets whose sums are identical. Print 0 if there are no such ways.
*****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

int main() {
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    fin >> N;
    fin.close();
    // 判断和是否是偶数，若不是，则直接返回
    int sum = 0;
    for(int i=1; i<=N; i++) {
        sum += i;
    }
    if(sum % 2) {
        fout << 0 << endl;
        fout.close();
    }
    // 动态规划，f[i][j]，表示在前i个数中选数使得加起来等于j，最终的结果输出应该是f[n][n*(n+1)/4] / 2
    long long f[40][800];
    f[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= i*(i+1)/2; j++) {
            f[i][j] = ((j-i >= 0) ? f[i-1][j]+f[i-1][j-i] : f[i-1][j]);
        }
    }
    fout << f[N][N*(N+1)/4] / 2 << endl;
    fout.close();

    return 0;
}
