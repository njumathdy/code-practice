/*******************
Given an unsorted integer array, find the smallest missing positive integer.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 首先，对于有n个数的数组，缺失的最小的正数一定在[1, n+1]之间
// 若找到正数i属于[1, n]，则将它放到第i-1个位置上，最后看哪个位置不符合即可。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;   
    }
};

int main() {
    return 0;
}