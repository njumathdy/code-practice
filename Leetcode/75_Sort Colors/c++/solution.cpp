/*******************
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 直接对颜色进行计数即可，然后再根据位置对数组每个元素赋值。需要遍历数组两次。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0;
        
        if(nums.size() < 1)
            return;
            
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                red++;
            if(nums[i] == 1)
                white++;   
        }
        
        for(int i = 0; i < red; i++)
            nums[i] = 0;
        for(int i = red; i < red+white; i++)
            nums[i] = 1;
        for(int i = red+white; i < nums.size(); i++)
            nums[i] = 2;
    }
};

int main() {
    return 0;
}