/*******************
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
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
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() < 2)
            return A;
        
        int i = 0, j = A.size() - 1;
        while(i < j) {
            while(i < A.size() && A[i] % 2 == 0)
                i++;
            while(j >= 0 && A[j] % 2)
                j--;
            if(i >= j)
                break;
            else {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        
        return A;
    }
};

int main() {
    return 0;
}