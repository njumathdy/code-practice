/*******************
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        
        int diff = A[1] - A[0];
        int n = A.size();
        vector<int> dp(n, 0);
        
        for(int i = 2; i < n; i++) {
            if(A[i] - A[i-1] == diff)
                dp[i] = dp[i-1] + 1;
            else {
                diff = A[i] - A[i-1];
            }
        }
        
        int res = 0;
        for(auto num : dp)
            res += num;
        
        return res;
    }
};

int main() {
    return 0;
}