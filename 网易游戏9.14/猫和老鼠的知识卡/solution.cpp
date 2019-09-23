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

const int mod = 1000000007;

int n, m;
vector<vector<int> > c(105, vector<int>(105, 0));
vector<vector<int> > sols;

void dfs(int a, int b, vector<int>& temp) {
    if(a < b) return;
    if(b == 0 && a == 0) {
        sols.push_back(temp);
        return;
    }
    if(b == 0) return;
    for(int i = 1; i <= a-b; i++) {
        temp.push_back(i);
        dfs(a-i, b-1, temp);
        temp.pop_back();
    }
}

void generate_c() {
    for(int i = 0; i <= 100; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}

void solve() {
    if(m == 1) {
        cout << 1 << endl;
        return;
    }
    
}

int main() {
    cin >> n >> m;
    generate_c();
    vector<int> temp;
    dfs(n, m, temp);
    solve();

    return 0;
}