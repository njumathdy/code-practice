/*******************
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// binary search
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, up = n;
        int mid;
        
        while(up > low) {
            mid = (low + up) / 2;
            int count = 0;
            for(auto num : nums) {
                if(num <= mid)
                    count++;
            }
            if(count > mid)
                up = mid;
            else
                low = mid+1;
        }
        return low;
    }
};

// Floyd's Tortoise and Hare
// 转化为一个有环链表的问题
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 0){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            fast = 0;
            while (fast != slow){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

int main() {
    return 0;
}