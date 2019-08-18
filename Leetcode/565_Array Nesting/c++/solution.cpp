/*******************
A zero-indexed array A of length N contains all integers from 0 to N-1. 
Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… 
By that analogy, we stop adding right before a duplicate element occurs in S.
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
    int arrayNesting(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int n = nums.size();
        
        vector<int> l(n, 0);
        for(int i = 0; i < n; i++) {
            if(l[i] > 0)
                continue;
            int c = 1, j = i;
            while(nums[j] != i) {
                j = nums[j];
                c++;
            }
            j = i;
            for(int k = 0; k < c; k++) {
                l[j] = c;
                j = nums[j];
            }
        }
        
        int res = 0;
        for(auto num : l)
            res = max(res, num);
        
        return res;
    }
};

int main() {
    return 0;
}