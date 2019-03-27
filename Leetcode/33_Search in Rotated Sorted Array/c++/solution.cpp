/*******************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 思路：二分法，注意各类判别条件即可。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        
        int start = 0, end = len - 1;
        
        while(end >= start) {
            int middle = (start + end) >> 1;
            if(nums[middle] == target)
                return middle;
            if(nums[middle] >= nums[start]) {
                if(target > nums[middle])
                    start = middle + 1;
                else if(target >= nums[start])
                    end = middle - 1;
                else 
                    start = middle + 1;        
            } else {
                if(target >= nums[start] || target < nums[middle])
                    end = middle - 1;
                else 
                    start = middle + 1;
            }
        }
        
        return -1;       
    }
};

int main() {
    return 0;
}