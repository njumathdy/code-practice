/*******************
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// hashtable的思想
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> > index;
        for(int i = 0; i < nums.size(); i++) {
            if(index.find(nums[i]) != index.end())
                index[nums[i]].push_back(i);
            else
                index[nums[i]] = {i};
        }
        for(auto iter = index.begin(); iter != index.end(); iter++) {
            if(iter->second.size() == 1)
                continue;
            else {
                for(int i = 0; i < iter->second.size()-1; i++) {
                    if(iter->second[i+1]-iter->second[i] <= k)
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}