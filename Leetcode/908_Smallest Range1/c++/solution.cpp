/*******************
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
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
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() < 2)
            return 0;
        
        int min_num = A[0], max_num = A[0];
        for(auto num : A) {
            min_num = min(num, min_num);
            max_num = max(num, max_num);
        }
        
        return max(0, max_num - min_num - 2*K);
    }
};

int main() {
    return 0;
}