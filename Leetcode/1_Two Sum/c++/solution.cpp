/*******************
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

// hash table
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            if(m.find(target - nums[i]) != m.end() && m.find(target-nums[i])->second != i) {
                ans = {i, m.find(target-nums[i])->second};
                break;
            }
        }
        return ans;
    }
};

// 只用一次循环，用unorder_map可以提高速度
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        for(int i = 0 ; i< nums.size(); i++){
            int remaining = target - nums[i];
            if(map.find(remaining)!=map.end()){
                return {map[remaining], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    return 0;
}