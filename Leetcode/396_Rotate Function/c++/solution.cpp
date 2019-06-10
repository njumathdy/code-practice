/*******************
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 注意int可能溢出的问题
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty())
            return 0;
        
        long long sum1 = 0, sum2 = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            sum1 += A[i];
            sum2 += i * A[i];
        }
        long long res = sum2;
        for(int i = 0; i < n - 1; i++) {
            sum2 = sum2 - sum1 + (long long)n * A[i];
            res = max(res, sum2);
        }
        
        return res;
    }
};

int main() {
    return 0;
}