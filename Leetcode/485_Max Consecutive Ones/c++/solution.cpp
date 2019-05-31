/*******************
Given a binary array, find the maximum number of consecutive 1s in this array.
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                continue;
            int j = i;
            while(j < nums.size() && nums[j] != 0) {
                j++;
            }
            res = max(res, j-i);
            i = j;
        }
        
        return res;
    }
};

int main() {
    return 0;
}