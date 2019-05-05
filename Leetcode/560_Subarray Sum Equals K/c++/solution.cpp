/*******************
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

// O(n^2) time, O(n) space
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size(), res = 0;
        vector<int> sum(n+1, 0);
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n+1; j++) {
                if(sum[j] - sum[i] == k)
                    res++;
            }
        }
        return res;
    }
};

// O(n^2) time, O(1) space
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k)
                    res++;
            }
        }
        return res;
    }
};

// based on map, O(n) time, O(n) space
class Solution3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size(), res = 0, sum = 0;
        map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(m.find(sum - k) != m.end()) {
                res += m[sum-k];
            }
            if(m.find(sum) != m.end())
                m[sum]++;
            else
                m[sum] = 1;    
        }
        
        return res;
    }
};

int main() {
    return 0;
}