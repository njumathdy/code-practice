/*******************
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.
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
private:
    const int mod = 1000000000 + 7;
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int> > dp(d + 1, vector<int>(target + 1, 0));
        for(int i = 1; i <= target; i++){
            if(i <= f) dp[1][i] = 1;
            else dp[1][i] = 0;
        }
        for(int i = 2; i <= d; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 1; k <= f; k++){
                    if(j - k >= 1){
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                    }
                }
            }
        }
        
        return dp[d][target];
    }
};

int main() {
    return 0;
}