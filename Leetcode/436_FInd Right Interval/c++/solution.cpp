/*******************
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. 
Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int> >& intervals) {
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }
        
        vector<int> res;
        for(auto x : intervals) {
            auto iter = m.lower_bound(x[1]);
            if(iter != m.end())
                res.push_back(iter->second);
            else
                res.push_back(-1);
        }
    
        return res;
    }
};

int main() {
    return 0;
}