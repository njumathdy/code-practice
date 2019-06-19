/*******************
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
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
    string addStrings(string num1, string num2) {
        if(num1.empty())
            return num2;
        if(num2.empty())
            return num1;
        
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size(), m = num2.size();
        int i = 0;
        int carry = 0;
        while(i < n && i < m) {
            int temp = num1[i] - '0' + num2[i] - '0' + carry;
            if(temp > 9)
                carry = 1;
            else
                carry = 0;
            res += ('0' + temp % 10);
            i++;
        }
        while(i < n) {
            int temp = num1[i] - '0' + carry;
            if(temp > 9)
                carry = 1;
            else 
                carry = 0;
            res += ('0' + temp % 10);
            i++;
        }
        while(i < m) {
            int temp = num2[i] - '0' + carry;
            if(temp > 9)
                carry = 1;
            else 
                carry = 0;
            res += ('0' + temp % 10);
            i++;
        }
        if(carry)
            res += '1';
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main() {
    return 0;
}