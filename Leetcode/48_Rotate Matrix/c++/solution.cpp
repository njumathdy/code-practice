/*******************
 * You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
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

// 旋转90度可以视作两次的对称操作，考虑到这点实现起来就比较容易。
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {    
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i + 1; j<matrix.size(); j++) {
                 int tmp = matrix[j][i];
                 matrix[j][i] = matrix[i][j];
                 matrix[i][j] = tmp;
			}
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    return 0;
}
