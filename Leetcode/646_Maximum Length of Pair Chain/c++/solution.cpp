/*******************
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// dp, time complexity: O(n^2)
class Solution1 {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        if(pairs.size() < 2) return pairs.size();
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[0] - b[0] < 0;
        };
        sort(pairs.begin(), pairs.end(), comp);
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                if(pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        
        int res = 0;
        for(auto x : dp)
            res = max(res, x);
        
        return res;
    }
};

// greedy, time complexity: O(n)
class Solution2 {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        if(pairs.size() < 2) return pairs.size();
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[1] - b[1] < 0;
        };
        sort(pairs.begin(), pairs.end(), comp);
        
        int n = pairs.size(), res = 0;
        int cur = INT_MIN;
        for(auto pair : pairs) {
            if(cur < pair[0]) {
                cur = pair[1];
                res++;
            }
        }
        
        return res;
    }
};

int main() {
    return 0;
}