/*******************
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
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
    bool isPowerOfFour(int num) {
        if(num == 0)
            return false;
        if(num == 1 || num == 4)
            return true;
        else {
            if(num % 4)
                return false;
            else
                return isPowerOfFour(num / 4);
        }
    }
};

int main() {
    return 0;
}