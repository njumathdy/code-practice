/*******************
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  
It is guaranteed this sum fits into a 32-bit integer.
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
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() < 2)
            return 0;
        
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < n-1; i++) {
            dp[i][i+1] = arr[i] * arr[i+1];
            dp[i][i] = 0;
        }
        dp[n-1][n-1] = 0;
        for(int k = 2; k < n; k++) {
            for(int i = 0; i < n - k; i++) {
                for(int j = i; j <= i+k-1; j++) {
                    dp[i][i+k] = min(maxElement(arr, i, j)*maxElement(arr, j+1, i+k) +
                                    dp[i][j] + dp[j+1][i+k], dp[i][i+k]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    int maxElement(vector<int>& arr, int l, int r) {
        int res = 0;
        for(int i = l; i <= r; i++)
            res = max(res, arr[i]);
        
        return res;
    }
};

class Solution2 {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() < 2)
            return 0;
        
        vector<int> stack = {INT_MAX};
        int res = 0;
        for(auto a : arr) {
            while(stack.back() <= a) {
                int tmp = stack.back();
                stack.pop_back();
                res += tmp * min(stack.back(), a);
            }
            
            stack.push_back(a);
        }
        
        for(int i = 1; i < stack.size()-1; i++)
            res += stack[i] * stack[i+1];
        
        return res;
    }   
};

int main() {
    return 0;
}