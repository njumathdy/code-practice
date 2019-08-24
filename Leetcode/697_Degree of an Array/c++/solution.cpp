/*******************
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int> > m;
        int degree = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = {i};
            else
                m[nums[i]].push_back(i);
            
            degree = max(degree, int(m[nums[i]].size()));
        }
        int res = nums.size();
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second.size() == degree)
                res = min(res, iter->second.back()-iter->second[0]+1);
        }
        
        return res;
    }
};

int main() {
    return 0;
}