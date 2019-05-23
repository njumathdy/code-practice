/*******************
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

此题还有扩展，将小朋友排成一个圈，其余条件相同，求最少的糖果数。（字节跳动笔试第3题）
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
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        
        int n = ratings.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1])
                dp[i] = dp[i-1] + 1;
        }
        int sum = dp[n-1];
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                dp[i] = max(dp[i], dp[i+1]+1);
            sum += dp[i];
        }
        
        return sum;
    }   
};

int main() {
    return 0;
}