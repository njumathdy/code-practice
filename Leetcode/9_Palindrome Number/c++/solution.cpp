/*******************
Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the same backward as forward.
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
    bool isPalindrome(int x) {
        if(x == 0)
            return true;
        if(x < 0 || x % 10 == 0)
            return false;
        
        string s = to_string(x);
        int i = 0, j = s.size()-1;
        while(i <= j) {
            if(s[i++] != s[j--])
                return false;
        }
        
        return true;
    }
};

int main() {
    return 0;
}