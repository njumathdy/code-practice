/*******************
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

// 利用栈
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        if(heights.size() == 1)
            return heights[0];
        
        int max_area = 0;
        int area;
        int tp;
        int n = heights.size(), i = 0;
        stack<int> s;
        
        while(i < n) {
            if(s.empty() || heights[s.top()] <= heights[i]) 
                s.push(i++);
            else {
                tp = s.top();
                s.pop();
                area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(area, max_area);
            }
        }
        
        while(!s.empty()) {
            tp = s.top();
            s.pop();
            area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(area, max_area);
        }
        
        return max_area;
    }
};

// 无需额外空间，更简洁
class Solution2 {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i + 1 < height.size() && height[i] <= height[i + 1]) {
                continue;
            }
            int minH = height[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}