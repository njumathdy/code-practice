/*******************
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < m && nums2[j-1] > nums1[i]) {
                iMin = i + 1;
            } else if(i > 0 && nums1[i-1] > nums2[j]) {
                iMax = i - 1;
            } else {
                int maxLeft = 0;
                if(i == 0) {
                    maxLeft = nums2[j-1];
                } else if(j == 0) {
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                
                if((m+n)%2 == 1)
                    return maxLeft;
                
                int minRight = 0;
                if(i == m) {
                    minRight = nums2[j];
                } else if(j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }
                
                return (maxLeft + minRight) / 2.0;   
            }
        }
        
        return 0.0;    
    }
};

int main() {
    return 0;
}