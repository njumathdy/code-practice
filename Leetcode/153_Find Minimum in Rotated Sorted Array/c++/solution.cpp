/*******************
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找。
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        if(nums.size() == 1 || nums[nums.size()-1] > nums[0])
            return nums[0];
            
        int begin = 0, end = nums.size() - 1;
        int middle;
        while(end > begin) {
            middle = begin + (end - begin) / 2;
            if(nums[middle] > nums[middle+1])
                return nums[middle+1];
            if(nums[middle] > nums[begin])
                begin = middle;
            else
                end = middle;
        }
        return min(nums[begin+1], nums[begin]);
    }
};

int main() {
    return 0;
}