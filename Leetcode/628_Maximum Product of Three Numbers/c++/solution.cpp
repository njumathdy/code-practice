/*******************
Given an integer array, find three numbers whose product is maximum and output the maximum product.
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
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if(nums[i] < min2) {
                min2 = nums[i];
            }
            
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if(nums[i] > max3) {
                max3 = nums[i];
            }
        }
        
        return max(max1*max2*max3, max1*min1*min2);
    }
};

int main() {
    return 0;
}