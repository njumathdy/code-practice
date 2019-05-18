/*******************
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
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
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        
        long long base = 1;
        int res = 0;
        long long low = 0, high = 0, curr = 0;
        
        while(n / base > 0) {
            low = n - (n / base) * base;
            curr = (n / base) % 10;
            high = ((long long)n) / (base * 10);
            
            switch(curr) {
                case 0:
                    res += high * base;
                    break;
                case 1:
                    res += high * base + low + 1;
                    break;
                default:
                    res += (high + 1) * base;
            }
            
            base *= 10;
        }
        return res;
    }
};

int main() {
    return 0;
}