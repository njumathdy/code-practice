/*******************
Given an integer, write a function to determine if it is a power of three.
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
    bool isPowerOfThree(int n) {
        long long base = 1; // 防止溢出
        while(base < n)
            base *= 3;
        
        return n == base;   
    }
};

class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0; 
    }
};

class Solution3 {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1 || n==3) {
            return true;
        }
        else {
            if(n%3){
                return false;
            }
            else{
                return isPowerOfThree(n/3);
            }
        }
    }
};

int main() {
    return 0;
}