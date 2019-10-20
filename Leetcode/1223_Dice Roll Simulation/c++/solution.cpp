/*******************
A die simulator generates a random number from 1 to 6 for each roll. 
You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 
Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.
Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.
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
    int mod = 1e9 + 7;
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int> > > cache(5010, vector<vector<int> >(16, vector<int>(6, -1)));
        
        return dfs(0, 0, n, rollMax, cache);
    }
    
    int dfs(int k, int num, int n, vector<int>& rollMax, vector<vector<vector<int> > >& cache) {
        if(n == 0) return 1;
        if(cache[n][k][num] > 0) return cache[n][k][num];
        
        int ans = 0;
        for(int i = 0; i < 6; i++) {
            if(i != num) 
                ans = (ans + dfs(1, i, n-1, rollMax, cache)) % mod;
            else if(k < rollMax[i])
                ans = (ans + dfs(k+1, i, n-1, rollMax, cache)) % mod;
        }
        cache[n][k][num] = ans;
        return ans;
    }
};

int main() {
    return 0;
}