/*******************
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 按位相加，注意进位即可
class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "0" && b == "0")
            return "0";

        if(a.size() < b.size())
            swap(a, b);
        
        string ans(a.size()+1, '0');
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int len1 = b.size();
        int len2 = a.size();
        int carry = 0;
        for(auto i = 0; i < len1; i++) {
            int tmp = (a[i]-'0'+b[i]-'0') + carry;
            ans[i] = tmp % 2 + '0';
            carry = tmp / 2;
        }
        for(auto i = len1; i < len2; i++) {
            int tmp = a[i] - '0' + carry;
            ans[i] = tmp % 2 + '0';
            carry = tmp / 2;
        }
        ans[len2] = carry + '0';
        
        reverse(ans.begin(), ans.end());
        size_t startpos = ans.find_first_not_of("0");
        
        return ans.substr(startpos);   
    }
};

int main() {
    Solution sol;
    string a = "11", b = "1";
    cout << sol.addBinary(a, b) << endl;

    return 0;
}