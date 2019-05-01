/*******************
Given a non-empty array of integers, every element appears twice except for one. 
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
        for(int i = 0; i < nums.size(); i++) 
            res ^= nums[i];
        
        return res;
    }
};

int main() {
    return 0;
}