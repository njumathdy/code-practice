#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int w[MAXN];    // 重量 
int v[MAXN];    // 价值 
int s[MAXN];    // 物品数量 
int f[MAXN];    // f[i][j], j重量下前i个物品的最大价值 


int main() {
    int n;
    int m;  // 背包重量 
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        cin >> w[i] >> v[i] >> s[i];

    for(int i = 1; i <= n; ++i)
        for(int j = m; j>=0; --j)   
            for(int k = 1; k <= s[i]; ++k) 
                if(j>=k*w[i])
                    f[j] = max(f[j], f[j-k*w[i]]+k*v[i]);

    cout << f[m] << endl;

    return 0;
}