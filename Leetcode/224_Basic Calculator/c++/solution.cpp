/*******************
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
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
    int calculate(string s) {
        stack<int> ops({1, 1});
        int total = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                int num = 0;
                while(i < s.size() && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i--;
                total += ops.top() * num;
                ops.pop();
            }
            else if(s[i] == ')')
                ops.pop();
            else if(s[i] != ' ')
            {
                int tmp = (s[i] == '-' ? -1 : 1) * ops.top();
                ops.push(tmp);
            }
        }
        return total;
    }
};

int main() {
    return 0;
}