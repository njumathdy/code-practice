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

string str;
set<string> str_table;
bool res = false;

void dfs(vector<int>& index) {
    int i = index.back();
    if(str_table.find(str.substr(i+1, str.size()-i-1)) != str_table.end()) {
        res = true;
        return;
    }
    int j = 1;
    while(i + j < str.size()) {
        if(str_table.find(str.substr(i+1, j)) != str_table.end()) {
            index.push_back(i+1+j-1);
            dfs(index);
            index.pop_back();
        }
        j++;
    }         
}

void solve() {
    vector<int> index;
    index.push_back(-1);
    dfs(index);
}

int main() {
    cin >> str;
    string temp;
    while(cin >> temp)
        str_table.insert(temp);

    solve();
    if(res)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}