/*******************
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
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
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return {};
        if(nums.size() == 4) {
            if(nums[0] + nums[1] + nums[2] + nums[3] == target)
                return {nums};
            else
                return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        
        int n = nums.size();
        for(int i = 0; i < n-3;) {
            for(int j = i+1; j < n-2;) {
                int start = j+1, end = n-1;
                while(end > start) {
                    if(nums[start] + nums[end] + nums[j] == target - nums[i]) {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while(start < end && nums[start] == nums[start-1])
                            start++;
                        while(start < end && nums[end] == nums[end+1])
                            end--;
                    } else if(nums[start] + nums[end] + nums[j] > target - nums[i]) {
                        end--;
                        while(nums[end] == nums[end+1] && start < end)
                            end--;
                    } else {
                        start++;
                        while(nums[start] == nums[start-1] && start < end)
                            start++;
                    }
                }
                j++;
                while(nums[j] == nums[j-1] && j < n-2)
                    j++;        
            }
            i++;
            while(nums[i] == nums[i-1] && i < n-3)
                i++;
        }
        return ans;
        
    }
};

// Leetcode优秀解法：可以适用与k Sum的问题。
class Solution2 {
private:
    const int K = 4;
    int size = 0;
    void search(vector<int>& nums, int pos, int k, int target, vector<int>& v, vector<vector<int> >& vv)
    {
        if(k == 2)
        {
            int l = pos, r = size-1;
            while(l < r)
            {
                int t = nums[l]+nums[r];
                if(t > target) r--;
                else if(t < target) l++;
                else {
                    v[K-2] = nums[l++];
                    v[K-1] = nums[r--];
                    vv.push_back(v);
                    while(l<r && nums[l]==nums[l-1]) l++; //avoid duplicates;
                    while(l<r && nums[r]==nums[r+1]) r--; //avoid duplicates;
                }
            }
        }
        else
        {
            for(int top = size-k; pos <= top; ++pos)
            {
                int sum = 0;
                // 预先判断，提前剪枝
                for(int i = 0; i < k; i++) sum += nums[pos+i]; 
                // 最小值大于目标
                if(sum > target) break; //avoid futile searching;
                sum = nums[pos];
                // 最大值小于目标
                for(int i = 0; i < k-1; ++i) sum += nums[size-1-i];
                if(sum < target) continue; //avoid futile(无用的) searching;

                v[K-k] = nums[pos];
                search(nums, pos+1, k-1, target-nums[pos], v, vv);
                while(pos<=top && nums[pos+1]==nums[pos]) pos++; //avoid duplicates;
            }
        }
    }
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<vector<int> > vv;
        vector<int> v(K, 0);
        search(nums, 0, K, target, v, vv);
        return vv;
    }
};

int main() {
    return 0;
}