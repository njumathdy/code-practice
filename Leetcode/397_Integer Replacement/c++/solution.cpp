/*******************
Given a positive integer n and you can do operations as follow:
If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.

What is the minimum number of replacements needed for n to become 1?
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
    int integerReplacement(int n) {
        if(n < 1)
            return 0;
        // 防止溢出
        if(n == 2147483647)
            return 32;
        
        int res = 0;
        return helper(n, res);
    }
    
    int helper(int n, int res) {
        if(n == 1)
            return res;
        
        if(n % 2 == 0)
            return helper(n >>= 1, res+1);
        else
            return min(helper(n+1, res+1), helper(n-1, res+1));
        
    }
};

class Solution2 {
public:
    int integerReplacement(long n) {
        int count = 0;
        while(n != 1){
            if(n % 2 == 0) n = n / 2;
            else if((n / 2) % 2 == 0 || n / 2 == 1)
                n = n - 1;
            else
                n = n + 1;
            count++;
        }
        return count;
    }
};

int main() {
    return 0;
}