/*******************
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

// 直接遍历将对应位置的数填进去即可。
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        
        int start = 0;
        int num = 1;
        while(n > start * 2) {
            generateCore(matrix, n, start, num);
            start++;
        }
        return matrix;
    }
    
    void generateCore(vector<vector<int> >& matrix, int n, int start, int& num) {
        int endP = n - 1 - start;
        
        for(int i = start; i <= endP; i++) 
            matrix[start][i] = num++;
        
        if(start < endP) {
            for(int i = start+1; i <= endP; i++)
                matrix[i][endP] = num++;
            for(int i = endP-1; i >= start; i--)
                matrix[endP][i] = num++;
        }
        if(start < endP - 1) {
            for(int i = endP-1; i > start; i--)
                matrix[i][start] = num++;
        }
        
    }
};

int main() {
    return 0;
}


