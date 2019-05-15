/*******************
Write a program to find the n-th ugly number.
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
    int nthUglyNumber(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int nextIndex = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        while(nextIndex < n) {
            int min = Min(res[i2] * 2, res[i3] * 3, res[i5] * 5);
            res[nextIndex] = min;
            
            while(res[i2] * 2 <= min)
                i2++;
            while(res[i3] * 3 <= min)
                i3++;
            while(res[i5] * 5 <= min)
                i5++;
            
            ++nextIndex;
        }
        
        return res[n-1];
    }
    
    int Min(int num1, int num2, int num3) {
        int temp = min(num1, num2);
        return min(temp, num3);
    }
};

int main() {
    return 0;
}