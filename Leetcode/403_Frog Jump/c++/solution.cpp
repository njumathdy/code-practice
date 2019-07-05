/*******************
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:
The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
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
    bool canCross(vector<int>& stones) {
        if(stones.size() < 2)
            return true;
        
        int n = stones.size();
        vector<vector<bool> > dp(n, vector<bool>(n+1, false));
        dp[0][1] = true;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff= stones[i] - stones[j];
                if(diff < 0 || diff > n || !dp[j][diff]) continue;
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff-1] = true;
                if(diff + 1 <= n) dp[i][diff+1] = true;
                if(i == n-1)
                    return true;
            }
        }
        
        return false;
    }   
};

int main() {
    return 0;
}