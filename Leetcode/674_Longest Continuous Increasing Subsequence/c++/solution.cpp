/*******************
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
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
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int n = nums.size();
        int res = 1;
        int temp = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                temp++;
                if(i == n-1) res = max(res, temp);
            }
            else {
                res = max(res, temp);
                temp = 1;
            }
        }
        return res;     
    }
};

int main() {
    return 0;
}