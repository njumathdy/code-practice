/*******************
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int index = 0, count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[index]) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    index = i;
                    count = 1;
                }
            }
        }
        return nums[index];
    }
};

int main() {
    return 0;
}