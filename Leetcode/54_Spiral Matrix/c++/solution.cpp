/*******************
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 剑指offer, 分析不同情况即可
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n;
        if(m < 1)
            return ans;
        else
            n = matrix[0].size();
        if(n < 1)
            return ans;
        
        int start = 0;
        while(m > start * 2 && n > start * 2) {
            spiralCore(matrix, ans, n, m, start);
            start++;
        }
        
        return ans;
    }
    
    void spiralCore(vector<vector<int> >& matrix, vector<int>& num, int columns, int rows, int start) {
        int endX = columns - start - 1;
        int endY = rows - start - 1;
        
        for(int i = start; i <= endX; i++) {
            num.push_back(matrix[start][i]);
        }
        
        if(start < endY) {
            for(int i = start + 1; i <= endY; i++)
                num.push_back(matrix[i][endX]);
        }
        if(start < endX && start < endY) {
            for(int i = endX-1; i >= start; i--) 
                num.push_back(matrix[endY][i]);
        }
        if(start < endX && start < endY - 1) {
            for(int i = endY - 1; i > start; i--)
                num.push_back(matrix[i][start]);
        }
    }
};

int main() {
    return 0;
}