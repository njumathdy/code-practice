/*******************
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
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
    string reverseStr(string s, int k) {
        int n = s.size();
        if(n <= k) {
            reverse(s.begin(), s.end());
            return s;
        } else if(n <= 2*k) {
            reverse(s.begin(), s.begin()+k);         
            return s;
        } else {
            string res;
            res = reverseStr(s.substr(0, 2*k), k) + reverseStr(s.substr(2*k), k);
            return res;
        }
    }
};

int main() {
    return 0;
}