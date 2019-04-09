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

const int maxn = 666666666;

int n;
int ans = 0;
vector<int> dp(100001, 0);

int dfs(int n) {
    // if(n == 0)
    //     return dp[0];
    // int ans = 0;
    // for(int i = 1; i <= n; i++) {
    //     if(dp[n-i] > 0) {
    //         ans = (ans + dp[n-i]) % maxn;
    //     } else {
    //         ans = (ans + dfs(n-i)) % maxn;
    //     }
    // }
    // dp[n] = ans;
    // return ans;   
    int ans = 0;
    if(dp[n] > 0)
        return dp[n];
    else {
        for(int i = 1; i <= n; i++) {
            ans += dfs(n-i);
        }
    }
    dp[n] = ans;
    return dp[n];
}

void solve(int n) {
    if(n < 6) {
        cout << 0 << endl;
        return;
    }

    for(int i = 6; i <= n; i++) {
        ans = (ans + dfs(n-i)) % maxn;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    solve(n);
    dp[0] = 1;
    // cout << dfs(2) << endl;

    return 0;
}