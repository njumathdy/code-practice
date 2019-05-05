/*******************
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
Write an algorithm to reconstruct the queue.
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
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        if(people.size() == 0)
            return {};
        
        auto comp = [](const vector<int>& v1, const vector<int>& v2)
                    -> bool {return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);};
        sort(people.begin(), people.end(), comp);
        
        vector<vector<int> > res;
        for(auto& p : people)
            res.insert(res.begin() + p[1], p);
        return res;
    }
};

int main() {
    return 0;
}