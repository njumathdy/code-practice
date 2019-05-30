/*******************
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        
        int a = nums[0], b = INT_MAX;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > b)
                return true;
            else if(nums[i] > a)
                b = min(b, nums[i]);
            else
                a = nums[i];
        }
        return false;
    }
};

int main() {
    return 0;
}