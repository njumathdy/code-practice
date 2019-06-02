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

const int MOD = 1000000007;

int w, b;

void dfs(int w, int b, vector<int>& color, int h, int& c);

void solve(int w, int b) {
    int sum = w + b;
    if(sum == 1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    int h = 1;
    while(h * (h + 1) / 2 <= sum)
        h++;
    h--; 
    vector<int> color(h, 0);
    int c = 0;
    dfs(w, b, color, 0, c);
    cout << h << ' ' << c << endl;
}

void dfs(int w, int b, vector<int>& color, int h, int& c) {
    if(h == color.size()) {
        c = (c + 1) % MOD;
        return;
    }
    if(w < h+1 && b < h+1)
        return;

    if(w >= h+1) {
        color[h] = 1; // 表示白色
        dfs(w-h-1, b, color, h+1, c);
        color[h] = 0;
    }   
    if(b >= h+1) {
        color[h] = 2;
        dfs(w, b-h-1, color, h+1, c);
        color[h] = 0;
    }   
}

int main() {
    cin >> w >> b;
    solve(w, b);
    return 0;
}