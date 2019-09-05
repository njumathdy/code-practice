/*******************
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
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
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int prev = INT_MIN;
        int ans = 0;
        for(auto it: intervals) {
            if(it[0] >= prev) {
                prev = it[1];
            }else
                ++ans;
        }
        return ans;
    }
};

int main() {
    return 0;
}