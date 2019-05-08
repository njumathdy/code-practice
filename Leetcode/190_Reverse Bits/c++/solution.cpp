/*******************
Reverse bits of a given 32 bits unsigned integer.
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
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, temp;
        int i = 0;
        while(i < 32) {
            res <<= 1;
            res += (1 & n);
            n >>= 1;
            i++;
        }
        return res;
    }
};



int main() {
    return 0;
}