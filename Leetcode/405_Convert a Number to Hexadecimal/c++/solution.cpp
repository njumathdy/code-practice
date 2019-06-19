/*******************
Given an integer, write an algorithm to convert it to hexadecimal. 
For negative integer, two’s complement method is used.
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
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        string res;
        int count = 0;
        while(num && count < 8) {
            res += HEX[(num & 0xf)];
            num >>= 4;
            count++;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
    
private:
    const string HEX = "0123456789abcdef";
};

int main() {
    return 0;
}