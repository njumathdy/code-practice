/*******************
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
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

// topological sort
class Solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<bool> marked(numCourses, false);
        vector<bool> onStack(numCourses, false);
        vector<vector<int> > listOfEdges(numCourses);
        
        bool res = true;
        for(auto edge : prerequisites) {
            listOfEdges[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(marked[i])
                continue;
            else
                dfs(i, listOfEdges, marked, onStack, res);
        }
        return res;
    }
    
    void dfs(int i, vector<vector<int> >& listOfEdges, vector<bool>& marked, vector<bool>& onStack, bool& res) {
        marked[i] = true;
        onStack[i] = true;
        for(auto num : listOfEdges[i]) {
            if(!marked[num])
                marked[num] = true;
            if(onStack[num]) {
                res = false;
                return;
            } else {
                onStack[num] = true;
                dfs(num, listOfEdges, marked, onStack, res);
            }
        }
        onStack[i] = false;
    }
};

class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<vector<int> > edges (numCourses, vector<int>());
        for (auto& p : prerequisites) {
            degree[p[0]]++; // 入度
            edges[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; i++) if (degree[i] == 0) q.push(i);
        
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            for (auto& node : edges[now]) {
                if (--degree[node] == 0) q.push(node);
            }
        }
        
        for (int i=0; i<numCourses; i++) if (degree[i] != 0) return false;
        return true;
    }
};

int main() {
    return 0;
}