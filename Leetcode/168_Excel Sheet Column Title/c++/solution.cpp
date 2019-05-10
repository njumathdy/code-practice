/*******************
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
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
    string convertToTitle(int n) {
        string res = "";
        char tmp;

        while(n) {
            n -= 1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        
        return res;
    }
};

int main() {
    return 0;
}