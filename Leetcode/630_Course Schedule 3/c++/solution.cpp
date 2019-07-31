/*******************
There are n different online courses numbered from 1 to n. 
Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. 
You will start at the 1st day.
Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.
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

class Solution {
public:
    int scheduleCourse(vector<vector<int> >& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});
        priority_queue<int> heap;
        int now = 0;
        for (int i = 0; i < courses.size(); ++ i)
        {
            heap.push(courses[i][0]);
            now += courses[i][0];
            if (now > courses[i][1]) {
                now -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};

int main() {
    return 0;
}