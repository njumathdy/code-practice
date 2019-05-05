/*******************
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.
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
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> nums(26, 0);
        for(auto c : tasks)
            nums[c-'A']++;
        sort(nums.begin(), nums.end());
        int time = 0;
        
        while(nums[25] > 0) {
            int i = 0;
            while(i <= n) {
                if(nums[25] == 0)
                    break;
                if(i < 26 && nums[25-i] > 0)
                    nums[25 - i]--;
                time++;
                i++;
            }
            sort(nums.begin(), nums.end());
        }
        return time;
    }
};

int main() {
    return 0;
}