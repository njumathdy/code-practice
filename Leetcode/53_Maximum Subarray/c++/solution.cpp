/*******************
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        int curSum = 0;
        int greatestSum = 0x80000000;
        for(int i = 0; i < nums.size(); i++) {
            if(curSum <= 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            
            if(curSum > greatestSum)
                greatestSum = curSum;
        }
        
        return greatestSum;
    }
};

int main() {
    return 0;
}