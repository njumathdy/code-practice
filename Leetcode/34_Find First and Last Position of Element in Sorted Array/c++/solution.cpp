/*******************
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) { 
        if (!nums.size()) return {-1,-1};
        int m, l = 0, r = nums.size()-1, begin, end;
        
        // find begin
        while (l < r) {
            m = l + (r-l)/2;
            nums[m] >= t ? r = m : l = m+1;
        }
        if (nums[(begin=l)] != t) return {-1,-1};
        
        // find end
        r = nums.size()-1;
        while (l < r) {
            m = l + (r-l)/2;
            nums[m] <= t ? l = m+1 : r = m;
        } 
        if (nums[(end=l)] != t) end--;
        return {begin,end};
    }          
};

int main() {
    return 0;
}