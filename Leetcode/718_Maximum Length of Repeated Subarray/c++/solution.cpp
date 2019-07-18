/*******************
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
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
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        int n = A.size(), m = B.size();
        vector<vector<int> > memo(n+1, vector<int>(m+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(A[i] == B[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    res = max(res, memo[i][j]);
                }
            }
        }
        
        return res;
    }
};

int main() {
    return 0;
}