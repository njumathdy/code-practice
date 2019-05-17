/*******************
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
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
    vector<int> singleNumber(vector<int>& nums) {
        int flag = 0;
        for(auto num : nums)
            flag ^= num;
        
        int pos = findFirstBit1(flag);
        
        int res1 = 0, res2 = 0;
        for(auto num : nums) {
            if(isBit1(num, pos))
                res1 ^= num;
            else
                res2 ^= num;
        }
        
        vector<int> res;
        res.push_back(res1);
        res.push_back(res2);
        
        return res;
    }
    
    int findFirstBit1(int num) {
        int res = 0;
        while((num & 1) == 0 && res < 8 * sizeof(int)) {
            num >>= 1;
            res++;
        }
        return res;
    }
    
    bool isBit1(int num, int pos) {
        num = num >> pos;
        return num & 1;
    }
};

int main() {
    int a = 1, b = 0;
    int c = a ^ b;
    cout << c << endl;

    return 0;
}