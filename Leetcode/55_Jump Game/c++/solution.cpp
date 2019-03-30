/*******************
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

// 动态规划 & 贪婪算法: 重要的是状态的规定，这里我们规定状态是从index处能否跳到最右边。
class Solution {
public:
    bool canJump(vector<int>& nums) {
//         if(nums.size() < 1)
//             return true;
        
        
//         vector<bool> canArrive(nums.size(), false);
        
//         canArrive[nums.size() - 1] = true;
        
//         for(int i = nums.size() - 2; i >= 0; i--) {
//             int furthestJump = min(i + nums[i], int(nums.size()) - 1);
//             for(int j = i+1; j <= furthestJump; j++) {
//                 if(canArrive[j] == true) {
//                     canArrive[i] = true;
//                     break;
//                 }
//             }
//         }
        
//         return canArrive[0] == true;
        int lastPos = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i + nums[i] >= lastPos)
                lastPos = i;
        }
        
        return lastPos == 0;
    }
};

int main() {
    return 0;
}

