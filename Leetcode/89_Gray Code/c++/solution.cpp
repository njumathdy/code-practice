/*******************
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
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
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);        
        for (int i = 0; i < n; i++) {
            int curCount = result.size();
            while (curCount) {
                curCount--;
                int curNum = result[curCount];
                curNum += (1<<i);
                result.push_back(curNum);
            } 
        }
        return result;
    }
};

int main() {
    return 0;
}