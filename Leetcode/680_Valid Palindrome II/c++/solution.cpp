/*******************
Given a non-empty string s, you may delete at most one character. 
Judge whether you can make it a palindrome.
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
    bool validPalindrome(string s) {
        if(s.empty()) return true;
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n-1-i]) {
                int j = n-1-i;
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
    
    bool isPalindrome(string s, int i, int j) {
        if(i == j) return true;
        for(int k = i; k <= i + (j-i)/2; k++) {
            if(s[k] != s[j-k+i]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}