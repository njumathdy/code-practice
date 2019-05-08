/*******************
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. 
Find that single one.
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
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(auto num : nums) {
                sum += (num >> i) & 1;
            }
            sum %= 3;
            res |= (sum << i);
        }
        
        return res;
    }
};

int main() {
    return 0;
}