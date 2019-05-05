/*******************
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <bitset>
#include <numeric>

using namespace std;

// dp
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        
        int sum = 0;
        for(auto num : nums)
            sum += num;
        
        if(sum % 2)
            return false;
        
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(auto num : nums) {
            for(int i = target; i >= num; i--) {
                dp[i] = dp[i] % 100000007 + dp[i - num] % 100000007;
            }
        }
        return dp[target];
    }
};

// bitset
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 这里用‘|’使得我们可以记住之前达到过的状态
        for (auto n : nums) bits |= bits << n; 
        return !(sum & 1) && bits[sum >> 1];
    }
};

int main() {
    return 0;
}