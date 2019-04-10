/*******************
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// big integer multiplication
// 直接按照乘法定义计算
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
    
        for (int i = num1.size() - 1; i >= 0 ; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0'; // 本位的数字
                carry = tmp / 10; // 进位的数字
            }
            sum[i] += carry; // 第i位进位
        }
    
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};

int main() {
    string s = "abcdefg";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}