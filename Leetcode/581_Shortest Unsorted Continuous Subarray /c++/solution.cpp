/*******************
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

// based on sorting, time complexity: O(nlogn), space complexity: O(n)
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int n = nums.size();
        int l = -1, r = n-1;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < n; i++) {
            if(temp[i] != nums[i]) {
                l = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(temp[i] != nums[i]) {
                r = i;
                break;
            }
        }
        if(l == -1)
            return 0;
        else
            return r-l+1;   
    }
};

// based on stack, time complexity: O(n), space complexity: O(n)
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        stack<int> s;
        int n = nums.size();
        int l = n, r = 0;
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        return l == n ? 0 : r - l + 1;
    }
};

// O(n) time, O(1) space
class Solution3 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (max > nums[i]) {
                if (start == -1) 
                    start = i - 1;
                while (start - 1 >= 0 && nums[start - 1] > nums[i]) 
                    start--;
                end = i + 1;
            } else 
                max = nums[i];
        }
        return end - start;
    }
};

int main() {
    return 0;
}