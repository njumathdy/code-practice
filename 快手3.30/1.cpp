/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

int n;

void solve(vector<int>& num) {
    int res = 0;
    for(int i = 0; i < num.size(); i++) {
        res ^= num[i];
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    vector<int> num;
    int t;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        num.push_back(t);
    }
    solve(num);

    return 0;
}