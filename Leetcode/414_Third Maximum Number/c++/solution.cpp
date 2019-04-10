/*******************
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number.
The time complexity must be in O(n).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxId1 = 0;
        int maxId2 = -1;
        int maxId3 = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[maxId1] <= nums[i]) {
                if (nums[maxId1] < nums[i]) {
                    maxId3 = maxId2;
                    maxId2 = maxId1;
                    maxId1 = i;
                }
            } else if (maxId2 == -1 || nums[maxId2] <= nums[i]) {
                if (maxId2 == -1 || nums[maxId2] < nums[i]) {
                    maxId3 = maxId2;
                    maxId2 = i;
                }
            } else if (maxId3 == -1 || nums[maxId3] <= nums[i]) {
                if (maxId3 == -1 || nums[maxId3] < nums[i]) {
                    maxId3 = i;
                }
            }
        }
        if (maxId3 == -1) {
            return nums[maxId1];
        } else {
            return nums[maxId3];
        }  
    }
}; 

int main() {
    return 0;
}