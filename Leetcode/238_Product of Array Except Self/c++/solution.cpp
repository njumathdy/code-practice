/*******************
Given an array nums of n integers where n > 1,  
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i]
Note: Please solve it without division and in O(n).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// Leetcode上答案
// 思路是左右相乘
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();

        vector<int> out(N,1);
        if (N<2)
            return out;
        
        int rsP = nums[0];
        //Find right-side product
        for(int i = 1; i<N; i++){
            out[i] = rsP;
            rsP *= nums[i];
        }
        
        //Find Left-side * right-side product
        int lsP = nums[N-1];
        for(int i = N-2; i>=0 ; i--){
            out[i] *= lsP;
            lsP *= nums[i];
        }
                
        return out;
    }
};

int main() {
    return 0;
}