/*******************
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size())
            return 0;
        
        int start = 0, end = nums.size() - 1;
        int middle;
        
        while(start < end) {
            middle = (start + end) >> 1;
            if(target == nums[middle])
                return middle;
            else if(target > nums[middle]) {
                if(middle == nums.size() - 1 || target < nums[middle+1])
                    return middle+1;
                else
                    start = middle + 1;
            } else {
                if(middle == 0 || target > nums[middle-1])
                    return middle;
                else
                    end = middle - 1;
            }
        }
        
        if(target > nums[start])
            return start + 1;
        else 
            return start;
    }
};

int main() {
    return 0;
}