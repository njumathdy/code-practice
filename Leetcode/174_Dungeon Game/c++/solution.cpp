/*******************
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.empty() || dungeon[0].empty())
            return 0;
        
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        
        int i, j;
        for(i = m - 1; i >= 0; i--) {
            for(j = n - 1; j >= 0; j--) {
                int need = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};

int main() {
    return 0;
}