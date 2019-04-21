/*******************
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.
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
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n; 
            // 计算高度
            for(int j=0; j<n; j++) { 
                if(matrix[i][j]=='1') height[j]++; 
                else height[j]=0;
            }
            // 计算最左边的1
            for(int j=0; j<n; j++) { 
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // 计算最右边的1
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}    
            }
            // 计算矩形面积
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j])*height[j]);
        }
        return maxA;
    }
};

int main() {
    return 0;
}