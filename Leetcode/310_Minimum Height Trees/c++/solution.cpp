/*******************
For an undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format:
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution1 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        // Initialize the undirected graph
        vector<unordered_set<int> > adj(n);
        for (vector<int> p : edges) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }
        // Corner case
        vector<int> current;
        if (n == 1) {
            current.push_back(0);
            return current;
        }
        // Create first leaf layer
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i].size() == 1) {
                current.push_back(i);
            }
        }
        // BFS the graph
        while (true) {
            vector<int> next;
            for (int node : current) {
                for (int neighbor : adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) 
                        next.push_back(neighbor);
                    }
            }
            if (next.empty()) return current;
            current = next;
        }
    }
};

class Solution2 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        vector<bool> leaves(n + 1, false);
        vector<vector<int> > v(n + 1);
        vector<int> ne(n);
        if (n == 1)
            return {0};
        if (n == 2) {
            return {0, 1};
        }
        for (int i = 0; i < n - 1; ++i) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> g;
        int counter = 0;
        vector<int> levels(n);
        for (int i = 0; i < n; ++i) {
            ne[i] = v[i].size();
            if (v[i].size() == 1) {
                leaves[i] = true;
                counter++;
                g.push(i);
            }
        }
        
        int max_level = 0;
        while (n - counter > 0) {
            int p = g.front(), k = levels[p];
            g.pop();
            for (int i = 0; i < v[p].size(); ++i) {
                if (!leaves[v[p][i]] && ne[v[p][i]] == 2) {
                    leaves[v[p][i]] = true;
                    g.push(v[p][i]);
                    levels[v[p][i]] = k + 1;
                    max_level = max(max_level, k + 1);
                    ne[v[p][i]]--;
                    counter++;
                } else {
                    ne[v[p][i]]--;
                }
            }
            
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (levels[i] == max_level)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}