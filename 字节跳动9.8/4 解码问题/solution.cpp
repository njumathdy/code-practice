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

set<string> res;
string s;

char trans(int i) {
    return 'A' + i - 1;
}

void dfs(string str, int p, string temp) {
    if(p == str.size())
        res.insert(temp);

    if(str[p] == '0')
        return;
    
    char c = trans(str[p] - '0');
    
    dfs(str, p+1, temp+c);
    if(p < str.size()-1) {
        int i = stoi(str.substr(p, 2));
        if(i >= 10 && i <= 26) {
            char d = trans(i);
            dfs(str, p+2, temp+d);
        }
    }

}

void solve(string str) {
    string temp = "";
    dfs(str, 0, temp);
}

int main() {
    cin >> s;
    solve(s);

    for(auto r : res)
        cout << r << endl;
    
    // string a = "123";
    // cout << a.substr(0, 1) << endl;

    return 0;
}