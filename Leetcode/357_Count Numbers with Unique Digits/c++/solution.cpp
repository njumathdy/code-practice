/*******************
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
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
    int permutation(int n, int r)
    {
        if(r == 0) {
            return 1;
        } else{
            return n * permutation(n - 1, r - 1);
        }
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if(n > 0)
        {
           int end = (n > 10)? 10 : n;
           for(int i = 0; i < end; i++)
           {
               sum += 9 * permutation(9, i);
           }
        }
        return sum;
    }
};

int main() {
    return 0;
}