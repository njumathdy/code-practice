/*******************
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
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
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int n = nums.size();
        // up[i]表示在i之前最长的以上升结束的wiggle sequence
        // down[i]表示在i之前最长的以下降结束的wiggle sequence
        vector<int> up(n, 0), down(n, 0);
        up[0] = down[0] = 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if(nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        
        return max(down[n-1], up[n-1]);
    }
};

int main() {
    return 0;
}