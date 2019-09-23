#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

vector<vector<int> > dp(2010, vector<int>(2010, 0));

void solve() {
    dp[0][0] = 1;
    for(int i = 1; i <= 2009; i++) dp[i][0] = 1;
    for(int i = 1; i <= 2009; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
        }
    }
    
    return;
}

int main() {
    int n, a, b;
    cin >> n;
    
    solve();
    
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }
    
    return 0;
}