/*******************
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        
        while(num >= 10) {
            int temp = 0;
            while(num > 0) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};

// digital root
class Solution2 {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main() {
    return 0;
}