/*******************
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
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
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        
        int n = height.size();
        int maxd = 0;
        for(int i = 0; i < n; i++)
            if(height[i] > height[maxd])
                maxd = i;
        
        int sum = 0, left = height.front();
        for(int i = 1; i < maxd; i++) {
            if(height[i] >= left)
                left = height[i];
            else
                sum += left - height[i];
        }
        
        int right = height.back();
        for(int i = n - 2; i > maxd; i--) {
            if(height[i] >= right)
                right = height[i];
            else
                sum += right - height[i];
        }
        
        return sum;
        
    }
};

int main() {
    return 0;
}