/*******************
Given an unsorted array of integers, find the length of longest increasing subsequence.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// time complexity: O(n^2)
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size(), i, j;
        vector<int> dp(n, 1);
        for(i = 1; i < n; i++) {
            for(j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        
        int res = 0;
        for(i = 0; i < n; i++)
            res = max(res, dp[i]);
        
        return res;
    }
};

// time complexity: O(nlogn)
class Solution2 {
private:
    void insertWithBS(vector<int>& tail, int num) {
        if (tail.empty()) {
            tail.push_back(num);
            return;
        }
        
        if (tail[0] >= num) {
            tail[0] = num;
            return;
        }
        
        if (tail[tail.size() - 1] < num) {
            tail.push_back(num);
            return;
        }
        
        int start = 0, end = tail.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (num == tail[mid]) {
                return;
            } else if (num > tail[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        tail[start] = num;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // tail中保存到现在为止的递增序列，将当前元素插入到tail中，保持tail有序
        vector<int> tail;
        for (auto num : nums) {
            insertWithBS(tail, num);
        }
        return tail.size();
    }
};

int main() {
    return 0;
}