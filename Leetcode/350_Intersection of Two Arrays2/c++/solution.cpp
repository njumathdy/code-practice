/*******************
Given two arrays, write a function to compute their intersection.

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        for(auto num : nums1) {
            if(table.find(num) == table.end())
                table[num] = 1;
            else
                table[num]++;
        }
        vector<int> res;
        for(auto num : nums2) {
            if(table.find(num) != table.end()) {
                if(table[num] > 0) {
                    res.push_back(num);
                    table[num]--;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}