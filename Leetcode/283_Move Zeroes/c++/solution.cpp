/*******************
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// two pointers
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return;
        
        int lastIndex = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) 
                nums[lastIndex++] = nums[i];
        }
        
        for(int i = lastIndex; i < n; i++) 
            nums[i] = 0;
    }
};

class Solution2 {
public: 
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};

int main() {
    return 0;
}