/*******************
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
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
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size()-2; i++) {
            int k = i+2;
            for(int j = i+1; j < nums.size()-1 && nums[i] != 0; j++) {
                k = binarySearch(nums, k, nums.size()-1, nums[i]+nums[j]);
                res += k - j - 1;
            }
        }
        
        return res;
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int x) {
        while(r >= l && r < nums.size()) {
            int mid = l + (r-l) / 2;
            if(nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};

int main() {
    return 0;
}