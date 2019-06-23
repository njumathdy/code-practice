/*******************
Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// based on sort, O(nlogn)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() < 2)
            return 0;
        
        sort(A.begin(), A.end());
        int n = A.size(), res = 0;
        
        int cur = A[0] + 1;
        
        for(int i = 1; i < n; i++) {
            if(A[i] < cur)
                res += cur - A[i];
            else
                cur = A[i];
            cur++;
        }
        
        return res;
    }
};

int main() {
    return 0;
}