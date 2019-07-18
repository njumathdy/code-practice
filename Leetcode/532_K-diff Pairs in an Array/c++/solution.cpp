/*******************
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
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
    int findPairs(vector<int>& nums, int k) {
        if(k < 0 || nums.empty())
            return 0;
        
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, res = 0;
        for(; i < nums.size(); i++) {
            j = max(j, i+1);
            while(j < nums.size() && nums[j] - nums[i] < k)
                j++;
            if(j < nums.size() && nums[j] - nums[i] == k)
                res++;
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};

int main() {
    return 0;
}