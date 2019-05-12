/*******************
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// bfs
class Solution1 {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> copies;
        
        queue<Node*> todo;
        Node* copy = new Node(node->val, {});
        copies[node] = copy;
        todo.push(node);
        while(!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            
            for(auto nei : cur -> neighbors) {
                if(copies.find(nei) == copies.end()) {
                    Node* temp = new Node(nei->val, {});
                    copies[nei] = temp;
                    todo.push(nei);
                }
                
                copies[cur] -> neighbors.push_back(copies[nei]);
            }
        }
        return copy;
    }
};

// dfs
class Solution2 {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};

int main() {
    return 0;
}