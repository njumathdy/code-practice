/*******************
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        
        int m = 0;
        int mi = 0;
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            for(int j = i; j < nums.size(); ++j) {
                if(nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
                    T[i] = 1 + T[j];
                    parent[i] = j;
                    
                    if(T[i] > m) {
                        m = T[i]; // 最大divisible set的长度
                        mi = i; // divisible set中最小的数
                    }
                }
            }
        }
        
        vector<int> ret;
        
        for(int i = 0; i < m; ++i) {
            ret.push_back(nums[mi]);
            mi = parent[mi];
        }

        return ret;
    }
};

int main() {
    return 0;
}