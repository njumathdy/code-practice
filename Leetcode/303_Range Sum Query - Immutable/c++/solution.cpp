/*******************
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

You may assume that the array does not change.
There are many calls to sumRange function.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for (int num : nums)
            sum.push_back(sum.back() + num);
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i]; 
    }
private:
    vector<int> sum;
};

int main() {
    return 0;
}