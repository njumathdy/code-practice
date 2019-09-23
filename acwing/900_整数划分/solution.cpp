#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int solve(int n) {
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    
    for(int j = 0; j <= n; j++) dp[0][j] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(i * j == 1)
                dp[i][j] = 1;
            else {
                if(i == j)
                    dp[i][j] = (dp[i][j-1] + 1) % mod;
                else if(i - j < j) 
                    dp[i][j] = (dp[i-j][i-j] + dp[i][j-1]) % mod;
                else
                    dp[i][j] = (dp[i-j][j] + dp[i][j-1]) % mod;
            }
        }
    }
    
    return dp[n][n];
}

int main() {
    int n; 
    cin >> n;
    int res = solve(n);
    cout << res << endl;
    
    return 0;
}


