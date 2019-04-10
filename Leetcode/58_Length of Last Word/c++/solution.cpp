/*******************
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
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
    int lengthOfLastWord(string s) {
        if(s.size() <= 0)
            return 0;
        
        int n = s.size();
        int i = n-1;
        int count = 0;
        
        while(i >= 0) {
            if(s[i] == ' ')
                i--;
            else {
                for(int j = i; j >= 0; j--) {
                    if(s[j] != ' ')
                        count++;
                    else
                        break;
                }
                return count;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}