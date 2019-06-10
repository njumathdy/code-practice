/*******************
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. 
Thus, the itinerary must begin with JFK.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <stack>

using namespace std;

// 利用栈来辅助进行dfs，一个巧妙的点是构造图的时候使用了multiset<string>，其目的是使用
// 贪心算法，在每一次选择时首先选择字典序最小的目的地。
class Solution {
public:
    vector<string> findItinerary(vector<vector<string> >& tickets) {
        unordered_map<string, multiset<string> > graph;
        if(tickets.empty())
            return {};
        for(vector<string> ticket : tickets)
            graph[ticket[0]].insert(ticket[1]);
        
        vector<string> res;
        stack<string> dfs;
        dfs.push("JFK");
        
        while(!dfs.empty()) {
            string topAirport = dfs.top();
            if(graph[topAirport].empty()) {
                res.push_back(topAirport);
                dfs.pop();
            } else {
                dfs.push(*(graph[topAirport].begin()));
				graph[topAirport].erase(graph[topAirport].begin());
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}