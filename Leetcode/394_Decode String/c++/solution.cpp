/*******************
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
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

class Solution1 {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

// based on stack
class Solution2 {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); nums.pop();
            }
        }
        return res;
     }
};

int main() {
    return 0;
}