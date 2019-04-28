/*******************
Implement pow(x, n), which calculates x raised to the power n (x^n).
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
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n < 0) {
            if(n == -2147483648)
                return 1.0 / (myPow(x,2147483647) * x);
            else
                return 1.0 / myPow(x, -n);
        }
        double res = 1.0, t = x;
        while(n > 0) {
            if(n & 1)
                res *= t;
            n >>= 1;
            t *= t;
        }
        return res;
    }
};

int main() {
    return 0;
}