/*******************
Given a column title as appear in an Excel sheet, return its corresponding column number.
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
    int titleToNumber(string s) {
        if(s.size() == 0)
            return 0;
    
        int n = 0;
        for(auto c : s) {
            n *= 26;
            n += (c - 'A' + 1);
        }
        
        return n;
    }
};

int main() {
    return 0;
}