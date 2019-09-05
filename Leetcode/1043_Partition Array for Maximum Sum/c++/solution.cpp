/*******************
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.
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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            int cur_max = -1;
            
            for(int j = 1; j <= K && i - j >= 0; j++) {
                cur_max = max(cur_max, A[i-j]);
                dp[i] = max(dp[i], dp[i-j] + cur_max * j);
            }
        }
        
        return dp[n];
    }
};

int main() {
    return 0;
}