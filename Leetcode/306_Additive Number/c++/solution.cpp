/*******************
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
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
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size() / 2; i++){
            for(int j = 1; j <= (num.size()-i)/2; j++){
                if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) 
                    return true;
            }
        }
        return false;
    }
    
    bool check(string num1, string num2, string num){
        if(num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') 
            return false;
        string sum = add(num1, num2);
        if(num == sum) 
            return true;
        if(num.size() <= sum.size() || sum.compare(num.substr(0,sum.size()))!=0) 
            return false;
        else 
            return check(num2, sum, num.substr(sum.size()));
    } 
    
    string add(string n, string m){
        string res;
        int i = n.size()-1, j = m.size()-1, carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry + (i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
            res.push_back(sum%10+'0');
            carry = sum/10;
        }
        if(carry) 
            res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main() {
    return 0;
}