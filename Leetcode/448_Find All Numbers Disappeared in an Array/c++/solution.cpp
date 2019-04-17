/*******************
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) res.push_back(i+1);
        }
        return res; 
    }
};

// 每经过一个指标，我们将该该指标对应的数组的中数置为负数。
// 再遍历一遍数组，对应位置为正的数说明没有在数组中出现过。
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        for(int i=0;i<nums.size();++i)
        {
            int m = abs(nums[i])-1;
            nums[m] = nums[m]>0? -nums[m]: nums[m];
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i] > 0) res.push_back(i+1);
        return res;
    }
};

int main() {
    return 0;
}