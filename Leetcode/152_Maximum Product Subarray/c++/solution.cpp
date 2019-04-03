/*******************
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划，需要保存两个状态，一个是以该数字结尾的最大的乘积，另一个是以该数字结尾的最小的乘积。
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        int ans = INT_MIN;
        int curMax = 1, curMin = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                curMax = 0, curMin = 0;
            else {
                curMax = max(max(curMax*nums[i], curMin*nums[i]), nums[i]);
                curMin = min(min(curMax*nums[i], curMin*nums[i]), nums[i]);
            } 
            ans = max(ans, curMax);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int pMax=0, nMax=0, m = 0;
        for(int i=0; i<n; i++){
            if(nums[i]<0) swap(pMax, nMax);
            pMax = max(pMax*nums[i], nums[i]);
            nMax = min(nMax*nums[i], nums[i]);
            m = max(m, pMax);
        }
        return m;
    }
};

int main() {
    return 0;
}