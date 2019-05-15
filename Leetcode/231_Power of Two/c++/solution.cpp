/*******************
Given an integer, write a function to determine if it is a power of two.
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
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true;
        if(n > 1073741824)
            return false;
        
        int i = 1;
        while(i < n) {
            i <<= 1;
        }
        if(i == n)
            return true;
        
        return false;
    }
};

int main() {
    return 0;
}