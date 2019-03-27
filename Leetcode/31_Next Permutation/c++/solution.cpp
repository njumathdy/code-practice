/*******************
 * Leetcode31: 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 思路解析：要找到下一个数，若数组是降序排列，则已经是最大的。我们从右往左遍历，比较相邻的两个数，若前一个数比后一个数小，
// 则我们考虑将这个数与后面的比它大的数进行交换（选其中最小的那个），然后再将后面的数按照升序进行排列，即得到下一个数。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        int i = nums.size() - 2;
        while(i >= 0 && nums[i+1] <= nums[i]) 
            i--;
        
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j > i && nums[j] <= nums[i]) 
                j--;
            swap(nums, i, j);
        }
        reverse(nums, i + 1);         
    }
    
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while(i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
};

int main() {
    return 0;
}