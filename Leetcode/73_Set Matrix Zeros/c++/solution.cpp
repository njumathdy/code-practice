/*******************
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

// space complexity: O(m+n)
class Solution1 {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(m < 1) return;
        int n = matrix[0].size();
        if(n < 1) return;
        
        set<int> row_set;
        set<int> column_set;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row_set.insert(i);
                    column_set.insert(j);
                }    
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row_set.count(i) || column_set.count(j))
                    matrix[i][j] = 0;
            }
        }
        
    }
};

// space complexity: O(1)
class Solution2 {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool isCol = false; // 判断第一列是否要置零
        int m = matrix.size();
        if(m < 1) return;
        int n = matrix[0].size();
        if(n < 1) return;
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0)
                isCol = true;
            
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        
        if(isCol) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;      
        }
        
    }
};

int main() {
    

    return 0;
}
