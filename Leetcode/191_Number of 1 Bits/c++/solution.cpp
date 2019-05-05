/*******************
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t t = 1;
        while(t != 0) {
            if(t & n)
                res++;
            t <<= 1;
        }
        return res;
    }
};

class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int k = 0;
        
        while (n) {
            n &= (n - 1);
            k++;
        }
        
        return k;
    }
};

int main() {
    return 0;
}