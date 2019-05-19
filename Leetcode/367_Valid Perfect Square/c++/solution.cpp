/*******************
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
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
    bool isPerfectSquare(int num) {
        long r = num;
        // Newton method
        while (r*r > num)
            r = (r + num / r) / 2;
        
        return r*r == num;
    }
};

int main() {
    return 0;
}