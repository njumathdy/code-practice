/*******************
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
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
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int n = intervals.size();
        
        int i;
        for(i = 0; i < n; i++) {
            if(newInterval[1] < intervals[i][0])
                break;
            else if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;    
    }
};

int main() {
    return 0;
}