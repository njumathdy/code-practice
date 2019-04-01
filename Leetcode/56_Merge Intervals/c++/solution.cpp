/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for an interval.
 **/
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

// 解法1: 空间效率较高，但时间很慢，推测是因为频繁的erase和insert操作导致的
class Solution1 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 1; i < n; i++) {
            if(intervals[i].start <= intervals[i-1].end) {
                Interval temp = Interval(intervals[i-1].start, max(intervals[i-1].end, intervals[i].end));
                intervals.erase(intervals.begin()+i-1, intervals.begin()+i+1);
                intervals.insert(intervals.begin()+i-1, temp);
                i--;
                n--;
            }
        }
        return intervals;
        
    }
    
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
};

class Solution2 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;
        
        int cur = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= intervals[cur].end) {
                Interval temp = Interval(intervals[i-1].start, max(intervals[cur].end, intervals[i].end));
                intervals[cur] = temp;
            } else {
                cur++;
                intervals[cur] = intervals[i];
            }
        }
        return vector<Interval>(intervals.begin(), intervals.begin()+cur+1);   
    }
    
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
};

int main() {
    return 0;
}