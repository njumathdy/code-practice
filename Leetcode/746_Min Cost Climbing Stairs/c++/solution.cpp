/*******************
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
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
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())
            return 0;
            
        if(cost.size() == 1)
            return cost[0];
        if(cost.size() == 2)
            return min(cost[1], cost[2]);
        
        int n = cost.size();
        vector<int> dp(n, 0);
        
        dp[n-1] = cost[n-1]; dp[n-2] = cost[n-2];
        
        for(int i = n-3; i >= 0; --i) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};

int main() {
    return 0;
}