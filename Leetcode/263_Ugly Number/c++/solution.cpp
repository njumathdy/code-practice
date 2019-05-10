/*******************
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
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
    bool isUgly(int num) {
        for(int i = 2; i < 6 && num; i++) {
            while(num % i == 0)
                num /= i;
        }
        return num == 1;
    }
};

int main() {
    return 0;
}