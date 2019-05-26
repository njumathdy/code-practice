/*******************
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. 
It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
A key point is the left endpoint of a horizontal line segment. 
Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. 
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution1 {
public:
    vector<vector<int> > getSkyline(vector<vector<int> >& buildings) {
        multimap<int, int> A;
        vector<vector<int> > ans;
        for(int i = 0; i < buildings.size(); i++) {
            A.emplace(buildings[i][0], buildings[i][2]);
            A.emplace(buildings[i][1], -buildings[i][2]);
        }
        multiset<int> h;
        h.insert(0);
        for(auto iter = A.begin(); iter != A.end(); iter++) {
            int key = iter -> first;
            while(iter != A.end() && iter -> first == key) {
                if(iter -> second > 0) 
                    h.insert(iter -> second);
                else
                    h.erase(h.find(-iter -> second));
                iter++;
            }
            iter--;
            int height = *h.rbegin();
            if(ans.size() == 0 || height != ans.back()[1])
                ans.push_back({iter->first, height});
        }
        
        return ans;
    }
};

int main() {
    return 0;
}