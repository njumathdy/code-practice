/*******************
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
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
    int getSum(int a, int b){
        if (b)
            return getSum(a^b, ((a&b) & 0xffffffff) << 1);
        return a;
    }   
};

int main() {
    return 0;
}