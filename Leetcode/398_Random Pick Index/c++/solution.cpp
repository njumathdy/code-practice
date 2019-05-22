/*******************
Given an array of integers with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = -1;
        for(int i = 0 ; i < _nums.size(); i++){
            if(_nums[i] != target) continue;
            if(n == 0) {ans = i; n++;}
            else {
                n++;
                if(rand() % n == 0) {ans = i;} // with prob 1/(n+1) to replace the previous index
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}