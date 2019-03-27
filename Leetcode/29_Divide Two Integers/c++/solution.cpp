#include <limits.h>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend != INT_MIN && divisor != INT_MIN && abs(dividend) < abs(divisor))
            return 0;
        
        bool negative = (dividend > 0) ^ (divisor > 0);
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        
        int ans = 0; 
        while(dividend <= divisor) {
            int s = -1;
            int m = divisor;
            while(dividend - m <= m) {
                s += 1;
                m += 1;
            }
            ans += s;
            dividend -= m;
        }
            
        return negative ? ans : -ans;
    }
};