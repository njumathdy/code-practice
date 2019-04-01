/******************* 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
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

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        bool ans = false;
        
        int m = matrix.size();
        if(m < 1)
            return ans;
        int n = matrix[0].size();
        if(n < 1)
            return ans;
        
        int i = m-1, j = 0;
        while(i >= 0 && j < n) {
            if(target == matrix[i][j]) {
                ans = true;
                break;
            } else if(target < matrix[i][j]) {
                i--;
            } else
                j++;
        }
        
        return ans;
    }
};

int main() {
    return 0;
}
