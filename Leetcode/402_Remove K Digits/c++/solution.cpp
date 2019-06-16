/*******************
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";
        
        stack<char> s;
        int i = 0;
        while(i < num.size()) {
            while(k > 0 && !s.empty() && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
            i++;
        }
        while(k > 0) {
            s.pop();
            k--;
        }
        string res;
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        
        deleteLeadingZero(res);
        
        return res;
    }
    
    void deleteLeadingZero(string& s) {
        int i = 0;
        while(i < s.size() && s[i] == '0')
            i++;
        
        if(i == s.size())
            s = "0";
        else
            s.erase(0, i);
    }
};

int main() {
    return 0;
}