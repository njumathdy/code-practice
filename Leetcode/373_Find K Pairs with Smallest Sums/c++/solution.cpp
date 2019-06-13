/*******************
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

// based on heap
class Solution {
public:
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty() || k == 0)
            return {};
        
        vector<vector<int> > res;
        auto comp = [&nums1, &nums2](vector<int> a, vector<int> b) -> bool {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(comp)> min_heap(comp);
        min_heap.push({0, 0});
        while(k-- > 0 && min_heap.size()) {
            auto temp = min_heap.top();
            min_heap.pop();
            res.push_back({nums1[temp[0]], nums2[temp[1]]});
            if(temp[0] + 1 < nums1.size())
                min_heap.push({temp[0]+1, temp[1]});
            if(temp[0] == 0 && temp[1] + 1 < nums2.size())
                min_heap.push({temp[0], temp[1]+1});
        }
        
        return res;
    }
};

int main() {
    return 0;
}