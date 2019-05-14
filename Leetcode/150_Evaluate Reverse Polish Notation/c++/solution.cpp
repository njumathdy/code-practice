/*******************
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
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
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int n = tokens.size();
        
        int i = 0;
        while(i < n) {
            if(tokens[i] == "+") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1 + num2);
            } else if(tokens[i] == "-") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 - num1);
            } else if(tokens[i] == "*") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1 * num2);
            } else if(tokens[i] == "/") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 / num1);
            } else {
                nums.push(atoi(tokens[i].c_str()));
            }
            i++;
        }
        return nums.top();
    }
};

int main() {
    return 0;
}