/*******************
Alex and Lee continue their games with piles of stones.  
There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  
The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  
Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.
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
    int stoneGameII(vector<int>& piles) {
        if(piles.empty())
            return 0;
        
        int length = piles.size();
        vector<vector<int> > dp(length + 1, vector<int>(length + 1,0));
        vector<int> sufsum(length + 1, 0);
        for (int i = length - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i+1] + piles[i];
        }
        for (int i = 0; i <= length; i++) {
            dp[i][length] = sufsum[i];
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = length - 1; j >= 1; j--) {
                for (int X = 1; X <= 2 * j && i + X <= length; X++) {
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
                }
            }
        }
        return dp[0][1];
    }
};

int main() {
    return 0;
}