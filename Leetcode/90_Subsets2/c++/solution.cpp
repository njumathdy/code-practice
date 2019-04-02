/*******************
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// Leetcode用户代码。我的思路还是局限在不重复的情形然后想办法去重，没有更general的考虑问题。
// 假设每个元素的重复次数为a1,a2,...,an。则子集个数为(a1+1)(a2+1)...(an+1)
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > totalset = {{}};
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();){
            int count = 0; // num of elements are the same
            while(count + i<nums.size() && nums[count+i]==nums[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(nums[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
    }
};

int main() {
    return 0;
}