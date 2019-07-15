/*******************
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. 
The answer may be very large, return it after mod 109 + 7.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// recursion with memorization
class Solution1 {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int> > > memo(m, vector<vector<int> >(n, vector<int>(N+1, -1)));     
        return findPaths(m, n, N, i, j, memo);
    }
    
    int findPaths(int m, int n, int N, int i, int j, vector<vector<vector<int> > >& memo) {
        if(i == m || j == n || i < 0 || j < 0)
            return 1;
        if(N == 0)
            return 0;
        if(memo[i][j][N] >= 0)
            return memo[i][j][N];
        
        memo[i][j][N] = ((findPaths(m, n, N-1, i-1, j, memo) + findPaths(m, n, N-1, i+1, j, memo))%mod + (findPaths(m, n, N-1, i, j-1, memo) + findPaths(m, n, N-1, i, j+1, memo))%mod)%mod;
        return memo[i][j][N];
    }
private:
    const int mod = 1000000007;
};

int main() {
    return 0;
}