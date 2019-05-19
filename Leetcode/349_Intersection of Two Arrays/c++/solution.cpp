/*******************
Given two arrays, write a function to compute their intersection.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> table(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto num : nums2) {
            if(table.find(num) != table.end()) {
                res.push_back(num);
                table.erase(num);
            }
                
        }
        return res;
    }
};

int main() {
    return 0;
}