/*******************
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

// Leetcode: 太强了。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            // i < 2: 前两个一定不会重复超过两次
            // n > nums[i-1]: 说明n要满足不和前面两个以上的数重复
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

// 上面的方法虽然十分简洁，但是感觉很难想到。用两个指针的想法比较general
class Solutuon2 {
public: 
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3)
            return nums.size();

        int i = 1, j = 0, count = 1;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] == nums[j-1]) {
                count++;
                if(count < 3)
                    nums[i++] = nums[j];
            } else {
                count = 1;
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> case1 = {1,1,1,1,1,1};
    cout << sol.removeDuplicates(case1) << endl;
    return 0;
}