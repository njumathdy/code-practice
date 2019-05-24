/*******************
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for(int i=0;i<nums.size();i++) {
            if (i > k) window.erase(nums[i-k-1]);
            auto pos = window.lower_bound((long) nums[i] - t); 
            if (pos != window.end() && t >= *pos - nums[i]) 
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    return 0;
}