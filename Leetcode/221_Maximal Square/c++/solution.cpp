/*******************
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// dp
class Solution1 {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.empty())
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(n == 0)
            return 0;
        
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int cur_left, cur_right;
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            cur_left = 0;
            cur_right = n;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            for(int j=0; j<n; j++) { 
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // 计算最右边的1
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}    
            }
            
            for(int j = 0; j < n; j++)
                ans = max(ans, min(right[j]-left[j], height[j]) * min(right[j]-left[j], height[j]));
        }
        
        return ans;
    }
};

// Leetcode优秀解答
class Solution2 {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};

int main() {
    return 0;
}