/*******************
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, output -1 for this number.
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
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty())
            return {};
        
        int n = nums.size();
        vector<int> s, res(n, -1);
        
        for(int i = 0; i < n*2; i++) {
            while(s.size() && nums[s.back()] < nums[i % n]) {
                res[s.back()] = nums[i % n];
                s.pop_back();
            }
            s.push_back(i % n);
        }
        
        return res;        
    }
};

int main() {
    return 0;
}