/*******************
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

// 一开始想偷懒直接转化为整数运算，但是没有考虑到溢出问题。还是老老实实写循环。
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        if(digits.size() < 1) {
            ans.push_back(1);
            return ans;
        }
        
        int j = digits.size() - 1;
        while(j >= 0 && digits[j] == 9)
            j--;
            
        if(j == digits.size() - 1)
            digits[j] += 1;
        else if(j >= 0) {
            digits[j]++;
            for(int i = j+1; i < digits.size(); i++)
                digits[i] = 0;
        }
        else {
            digits.insert(digits.begin(), 1);
            for(int i = 1; i < digits.size(); i++)
                digits[i] = 0;
        }
            
        return digits;
        
    }
};

int main() {
    return 0;
}
