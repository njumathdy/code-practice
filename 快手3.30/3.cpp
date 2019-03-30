/*******************
 * 计算中缀表达式
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <deque>

using namespace std;

// 只过了40%
void cal(string& s) {
    int res = 0;
    int temp;
    deque<int> stack1;
    deque<char> stack2;
    set<char> v2 = {'+', '-', '*'};
    set<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < s.length(); i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            stack1.push_back((s[i]-'0'));
        }
        else if(s[i] == ')') {
            char sym = stack2.back();
            stack2.pop_back();
            stack2.pop_back(); // 将'('弹出
            int num1 = stack1.back();
            stack1.pop_back();
            int num2 = stack1.back();
            stack1.pop_back();
            if(sym == '+') {
                temp = num1 + num2;
                stack1.push_back(temp);
            } else if(sym == '-') {
                temp = num2  - num1 ;
                stack1.push_back(temp);
            } else {
                temp = num2 * num1 ;
                stack1.push_back(temp);
            }
        } else if(s[i] == '*') {
            if(s[i+1] != '(') {
                int num = stack1.back();
                stack1.pop_back();
                temp = num  * (s[i+1] - '0');
                stack1.push_back(temp);
                i++;
            } else {
                stack2.push_back(s[i]);
            }
        } else {
            stack2.push_back(s[i]);
        }  
    }

    while(stack2.size() > 0) {
        char sym = stack2.front();
        stack2.pop_front();

        int num1 = stack1.front();
        stack1.pop_front();
        int num2 = stack1.front();
        stack1.pop_front();

        if(sym == '+') {
            temp = num2 + num1;
            stack1.push_front(temp);
        } else {
            temp = num1 - num2;
            stack1.push_front(temp);
        }
    }
    res = stack1.front();

    cout << res << endl;
}

int main() {
    string s;
    cin >> s;
    if(s[0] == '+' || s[0] == '-') {
        s.insert(s.begin(), '0');
    }
    // cout << s << endl;
    cal(s);

    return 0;
}