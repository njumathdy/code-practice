/*******************
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
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
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        if(nums.size() * nums[0].size() != r * c)
            return nums;
        if(r * c == 0)
            return nums;
        
        vector<vector<int> > res(r, vector<int>(c, 0));
        int i = 0;
        while(i < r * c) {
            res[i / c][i % c] = nums[i / nums[0].size()][i % nums[0].size()];
            i++;
        }
        
        return res;
    }
};

int main() {
    return 0;
}