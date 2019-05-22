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

class Solution1 {
public:
    int getSum(int a, int b){
        if (b)
            return getSum(a^b, ((a&b) & 0xffffffff) << 1);
        return a;
    }   
};

class Solution2 {
public:
    int getSum(int a, int b) {
        bool carry_in = 0;
        bool carry_out = 0;
        int out = 0;
        for(int i = 0 ; i < (sizeof(int)*8); i++)
        {
            bool bit_a = a & (1<<i);
            bool bit_b = b & (1<<i);
            bool sum = 0;
            
            sum = bit_a ^ bit_b ^ carry_in;
            carry_out = (((bit_a & (~bit_b)) | ((~bit_a) & bit_b)) & carry_in) | (bit_a & bit_b);
            carry_in = carry_out;
            out |= (sum << i);
        }
        //std::cout << sizeof(int) << std::endl;
        return out;
    }
};


int main() {
    return 0;
}