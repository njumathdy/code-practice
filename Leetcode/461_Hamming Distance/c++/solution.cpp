/*******************
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
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
    int hammingDistance(int x, int y) {
        int res = 0;
        int z = x ^ y;
        while(z != 0) {
            if(z & 1)
                res++;
            z >>= 1;
        }
        
        return res;
    }
};

int main() {
    return 0;
}