/*******************
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// hashtable，本题用set实现会更快
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++) {
            if(count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}