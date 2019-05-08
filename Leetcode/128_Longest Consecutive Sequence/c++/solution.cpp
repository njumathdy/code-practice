/*******************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.
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
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for(auto num : nums)
            num_set.insert(num);
        
        int longestStreak = 0;
        
        for(auto num : num_set) {
            if(!num_set.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while(num_set.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        
        return longestStreak;
    }
};

int main() {
    return 0;
}