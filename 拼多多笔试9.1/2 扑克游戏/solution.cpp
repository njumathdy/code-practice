/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

void dfs(string s1, string s2, int i, string temp, string stra, set<string>& strategies) {
    if(i == s1.size()) {
        if(temp == s2 && strategies.find(stra) == strategies.end()) {
            strategies.insert(stra);
            return;
        } else 
            return;
    }
    if(s2.find(s1[i]) == string::npos) {
        stra += 'd';
        dfs(s1, s2, i+1, temp, stra, strategies);
    } else { 
        dfs(s1, s2, i+1, s1[i]+temp, stra+'l', strategies);
        dfs(s1, s2, i+1, temp+s1[i], stra+'r', strategies);
        dfs(s1, s2, i+1, temp, stra+'d', strategies);
    }
}

void solve(string s1, string s2) {
    for(auto c : s2) {
        if(s1.find(c) == string::npos) {
            cout << '{' << endl;
            cout << '}' << endl;
            return;
        }
    }

    set<string> strategies;
    string temp = "", stra = "";
    dfs(s1, s2, 0, temp, stra, strategies);

    cout << '{' << endl;
    for(auto s : strategies) {
        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << ' ';
            if(i == s.size()-1)
                cout << endl;
        }
    }
    cout << '}' << endl;

    return;
}

int main() {
    int n;
    string s1, s2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        solve(s1, s2);
    }

    return 0;
}