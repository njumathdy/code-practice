#include <bits/stdc++.h>

using namespace std;

int N, V;
vector<int> v(1005, 0), w(1005, 0);
vector<vector<int> > dp(1005, vector<int>(1005, 0));

int main() {
    cin >> N >> V;
    for(int i = 0; i < N; i++)
        cin >> v[i] >> w[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= V; j++) {
            if(j < v[i]) 
                dp[i+1][j] = dp[i][j];
            else 
                dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]] + w[i]);
        }
    }
    
    cout << dp[N][V] << endl;
    
    return 0;
}