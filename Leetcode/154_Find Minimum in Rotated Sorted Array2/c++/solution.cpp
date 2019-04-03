/*******************
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int left = 0, right = nums.size() - 1;
        int middle;
        while(left < right) {
            middle = left + (right - left) / 2;
            if(nums[middle] > nums[right])
                left = middle + 1;
            else if(nums[middle] < nums[right])
                right = middle;
            else
                right--;
        }
        return nums[left];
    }
};

int main() {
    return 0;
}