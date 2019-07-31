/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N;

struct Node {
    int length;
    int weight;
};

vector<Node> node(110);

int dfs(vector<Node>& s, vector<Node>& tmp) {
    if(s.empty()) 
        return tmp.size();
    
    vector<int> t_weight(tmp.size(), 0);
    for(int i = tmp.size()-2; i >= 0; i--) {
        t_weight[i] = t_weight[i+1] + tmp[i+1].weight;
    }
    int max_weight = INT_MAX;

    for(int i = 0; i < tmp.size(); i++) {
        max_weight = min(max_weight, 7 * tmp[i].weight - t_weight[i]);
    }

    int height = tmp.size();
    for(int i = 0; i < s.size(); i++) {
        if(s[i].length < tmp[tmp.size()-1].length && s[i].weight <= max_weight) {
            vector<Node> temp = s;
            tmp.push_back(s[i]);
            temp.erase(temp.begin()+i);
            height = max(height, dfs(temp, tmp));
            tmp.pop_back();
        }
    }

    return height;
}

void solve(vector<Node>& jimu) {
    int res = 0;
    for(int i = 0; i < jimu.size(); i++) {
        vector<Node> tmp = {};
        vector<Node> t = jimu;
        tmp.push_back(jimu[i]);
        t.erase(t.begin()+i);
        res = max(res, dfs(t, tmp));
    }

    cout << res << endl;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> node[i].length;
    for(int i = 0; i < N; i++)
        cin >> node[i].weight;
    
    solve(node);

    return 0;
}