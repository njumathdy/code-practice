/*******************
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
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
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        queue<int> nodes;
        vector<int> indegrees(numCourses, 0); // 入度
        int visit_node_size = 0;
        vector<int> result;
        
        for (auto item : prerequisites) {
            graph[item[1]].push_back(item[0]);
            ++indegrees[item[0]];
        }
        for (int node_id = 0; node_id < indegrees.size(); ++node_id) {
            if (indegrees[node_id] == 0) {
                nodes.push(node_id);
            }
        }
        while (!nodes.empty()) {
            ++visit_node_size;
            int node_id = nodes.front();
            nodes.pop();
            result.push_back(node_id);
            for (auto neighber_id : graph[node_id]) {
                --indegrees[neighber_id];
                if (indegrees[neighber_id] == 0) {
                    nodes.push(neighber_id);
                }
            }
        }
        
        return visit_node_size == numCourses ? result : vector<int>();
    }
};

// bfs
class Solution2 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    order.push_back(j);
                    break;
                }
            }
            if (j == numCourses) {
                return {};
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }        
        return order;
    }
private:
    typedef vector<vector<int> > graph;
    
    graph buildGraph(int numCourses, vector<vector<int> >& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};

// dfs
class Solution3 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> order;
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    typedef vector<vector<int> > graph;
    
    graph buildGraph(int numCourses, vector<vector<int> >& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    // false表示含有环，true表示无环
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
        // 已经在栈上出现过，说明有环
        if (todo[node]) {
            return false;
        }
        // 之前是否访问过该点
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int neigh : g[node]) {
            if (!acyclic(g, todo, done, neigh, order)) {
                return false;
            }
        }
        order.push_back(node);
        // 重置状态
        todo[node] = false;
        return true;
    }
};

int main() {
    return 0;
}