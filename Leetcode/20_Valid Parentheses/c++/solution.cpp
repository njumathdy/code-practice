/*******************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
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
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        
        stack<char> stac;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stac.push(s[i]);
            else if(s[i] == ')') {
                if(stac.empty() || stac.top() != '(')
                    return false;
                else
                    stac.pop();
            } else if(s[i] == ']') {
                if(stac.empty() || stac.top() != '[')
                    return false;
                else
                    stac.pop();
            } else {
                if(stac.empty() || stac.top() != '{')
                    return false;
                else
                    stac.pop();
            }       
        }
        return stac.empty();
    }
};

int main() {
    return 0;
}