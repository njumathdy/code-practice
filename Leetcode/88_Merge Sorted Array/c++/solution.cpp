/*******************
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 用merge sort的思想，但是这里需要注意的是要从后向前合并，因为从前向后合并会改变num1的数据。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() < 1)
            return;
        
        int index = m+n-1;
        int i = m-1, j = n-1;
        
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[index--] = nums1[i--];
            }
            else {
                nums1[index--] = nums2[j--];
            }
        }
        while(j >= 0)
            nums1[index--] = nums2[j--];   
    }
};

int main() {
    return 0;
}