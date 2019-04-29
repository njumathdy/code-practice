/*******************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
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
    bool isPalindrome(string s) {
        if(s.size() <= 1)
            return true;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.size();
        int begin = 0, end = n - 1;
        while(begin < end) {
            if(isValid(s[begin]) && isValid(s[end])) {
                if(s[begin] == s[end]) {
                    begin++;
                    end--;
                } else
                    return false;
            }  
            if(!isValid(s[begin]))
                begin++;
            if(!isValid(s[end]))
                end--;   
        }
        return true;
    }
    
    bool isValid(char c) {
        if(c - '0' >= 0 && c - '0' <= 9)
            return true;
        if(c - 'a' >= 0 && c - 'a' < 26)
            return true;
        
        return false;
    }
};

int main() {
    return 0;
}