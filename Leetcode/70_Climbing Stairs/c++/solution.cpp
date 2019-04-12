/*******************
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
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
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int a = 1, b = 2, temp;
        while(n >= 3) {
            temp = b;
            b = b + a;
            a = temp;
            n--;
        }
        return b;    
    }
};

int main() {
    return 0;
}