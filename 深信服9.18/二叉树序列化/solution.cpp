/*******************
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

int N;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(nullptr), right(nullptr) {}
};

void solve(Node* node) {
    if(node == nullptr) {
        cout << '#' << endl;
        return;
    }
    cout << node -> val << endl;
    solve(node -> left);
    solve(node -> right);
}

int main() {
    cin >> N;



    vector<string> node(N+1);
    string s;
    node.push_back("*");
    for(int i = 1; i <= N; i++) {
        cin >> s;
        node[i] = s;
    }

    if(N == 1) {
        cout << node[1] << endl;
        return 0;
    }

    queue<pair<Node*, int> > q;
    Node* root = new Node(stoi(node[1]));
    q.push(make_pair(root, 1));
    int index = 2;
    while(!q.empty()) {
        if(index > N) break;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto t = q.front();
            q.pop();
            if(index > N || node[index] == "#") t.first -> left = nullptr;
            else {
                Node* left = new Node(stoi(node[index]));
                t.first -> left = left;
                q.push(make_pair(left, index));
            }
            index++;
            if(index > N || node[index] == "#") t.first -> right = nullptr;
            else {
                Node* right = new Node(stoi(node[index]));
                t.first -> right = right;
                q.push(make_pair(right, index));
            }
            index++;
        }  
    }

    solve(root);

    return 0;
}