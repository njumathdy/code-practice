/*******************
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// sliding window
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(numbers[left] + numbers[right] != target && right > left) {
            if(numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }
        return {left+1, right+1};
    }
};

int main() {
    return 0;
}