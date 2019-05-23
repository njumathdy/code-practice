/*******************
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.
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
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n, "");
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                ans[i-1] = "FizzBuzz";
            } else if(i % 3 == 0) {
                ans[i-1] = "Fizz";
            } else if(i % 5 == 0) {
                ans[i-1] = "Buzz";
            } else {
                ans[i-1] = to_string(i);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret_vec(n);
        for(int i=1; i<=n; ++i)
        {
            if(0 == i%3)
            {
                ret_vec[i-1] += "Fizz";
            }
            if(0 == i%5)
            {
                ret_vec[i-1] += "Buzz";
            }
            if(ret_vec[i-1].empty())
            {
                ret_vec[i-1] += to_string(i);
            }
        }
        return ret_vec;
    }
};

int main() {
    return 0;
}