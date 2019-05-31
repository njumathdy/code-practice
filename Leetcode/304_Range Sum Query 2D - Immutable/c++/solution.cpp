/*******************
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class NumMatrix1 {
public:
    NumMatrix1(vector<vector<int> >& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        
        int n = matrix.size(), m = matrix[0].size();
        sum = vector(n, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                sum[i][j+1] = sum[i][j] + matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1; i <= row2; i++)
            res += sum[i][col2+1] - sum[i][col1];
        
        return res;
    }
private:
    vector<vector<int> > sum;
};

class NumMatrix2 {
private:
    vector<vector<int> > sum;
    
public:
    NumMatrix2(vector<vector<int> >& matrix) {
        
        int m = matrix.size();
        if (m == 0)
            return;
        
        int n = matrix[0].size();
        
        sum.resize(m+1);
        for (int i = 0; i <= m; i++)
            sum[i].resize(n+1);
        
        for (int i = 0; i < m; i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                res += matrix[i][j];
                sum[i+1][j+1] = sum[i][j+1] + res;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};

int main() {
    return 0;
}