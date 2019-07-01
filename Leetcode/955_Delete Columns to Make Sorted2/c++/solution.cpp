/*******************
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.
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
    int minDeletionSize(vector<string>& A) {
        if(A.size() < 2)
            return 0;
        
        int n = A.size(), m = A[0].size();
        int res = 0;
        bool flag;
        // end[i]表示第i个字符串是否还需要和第i+1个字符串比较
        vector<bool> end(n, false);
        
        for(int i = 0; i < m; i++) {
            flag = true;
            for(int j = 0; j < n-1; j++) {
                if(!end[j]) {
                    if(A[j][i] > A[j+1][i]) {
                        flag = false;
                        break;
                    }
                }
            }
            
            if(!flag)
                res++;
            else {
                for(int j = 0; j < n-1; j++) {
                    if(A[j][i] < A[j+1][i])
                        end[j] = true;
                }
            }
        }
        
        return res;
    }
};

int main() {
    return 0;
}