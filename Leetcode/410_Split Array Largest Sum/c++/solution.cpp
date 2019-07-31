/*******************
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. 
Write an algorithm to minimize the largest sum among these m subarrays.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// binary search
class Solution1 {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxn = 0, sum = 0;
        for(auto num : nums) {
            maxn = max(maxn, num);
            sum += num;
        }
        if(m == 1)
            return sum;
        
        int l = maxn, r = sum;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(helper(nums, m, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
    
    bool helper(vector<int>& nums, int m, int target) {
        int count = 1;
        int tmp = 0;
        for(auto num : nums) {
            tmp += num;
            if(tmp > target) {
                count++;
                tmp = num;
                if(count > m)
                    return false;
            }   
        }
        return true;
    }
};

// dp
class Solution2 {
public: 
    int splitArray(vector<int>& nums, int m) {
        int size = nums.size();
        vector<long> dp(size);
        dp[0] = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i] = nums[i] + dp[i-1];
        }
        for (int k = 2; k <= m; k++) {
            for (int i = size - 1; i >= 0; i--) {
                long cur_sum = 0;
                for (int j = i; j >= 0; j--) {
                    cur_sum += nums[j];
                    if (cur_sum >= dp[i])
                        break;
                    dp[i] = min(dp[i], max(cur_sum, dp[j-1]));
                }
            }   
        }
        return dp[size - 1];
    }
};

int main() {
    return 0;
}