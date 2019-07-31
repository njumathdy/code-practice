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

bool dfs(vector<string>& s, vector<string>& tmp, int n);

void solve(vector<string>& s) {
    vector<string> tmp = {};
    if(dfs(s, tmp, s.size())) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

bool dfs(vector<string>& s, vector<string>& tmp, int n) {
    if(tmp.size() == n) {
        if(tmp[n-1][tmp[n-1].size()-1] == tmp[0][0])
            return true;
        else 
            return false;
    }

    if(tmp.empty()) {
        tmp.push_back(s[s.size()-1]);
        s.pop_back();
        return dfs(s, tmp, n);
    }

    string t = tmp.back();
    bool res = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i][0] == t[t.size()-1]) {
            tmp.push_back(s[i]);
            string temp = s[i];
            s.erase(s.begin()+i);
            res = res || dfs(s, tmp, n);
            s.push_back(temp);
        }
    }
    return res;
}

int main() {
    vector<string> s;
    string tmp;
    while(cin >> tmp)
        s.push_back(tmp);
    solve(s);

    return 0;
}