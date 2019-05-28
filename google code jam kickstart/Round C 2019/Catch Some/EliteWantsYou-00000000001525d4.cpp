#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 1010;
const int Q = 100100;
const int MAGIC = 130;

using namespace std;

int n;
int k;
int a[N];
int b[N];
int d[N][2];
vector <int> v[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < N; i++){
                v[i].clear();
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                v[b[i]].push_back(a[i]);
        }
        for(int i = 1; i < N; i++){
                d[i][0] = 2e9;
                d[i][1] = 2e9;
        }
        d[0][0] = 0;
        int res = 2e9;
        // 遍历所有颜色
        for(int i = 1; i < N; i++){
                if(v[i].empty()){
                        continue;
                }
                sort(v[i].begin(), v[i].end());
                // 每种颜色作为最后一种颜色
                for(int j = k - 1; j >= 0; j--){
                        for(int h = 0; h < v[i].size(); h++){
                                if(j + h + 1 > k){
                                        break;
                                }
                                // 该种颜色不是最后一个颜色
                                d[j + h + 1][0] = min(d[j + h + 1][0], d[j][0] + 2 * v[i][h]);
                                // 该种颜色是最后一个颜色
                                d[j + h + 1][1] = min(d[j + h + 1][1], d[j][0] + v[i][h]);
                                // 该种颜色不是最后一个颜色
                                d[j + h + 1][1] = min(d[j + h + 1][1], d[j][1] + 2 * v[i][h]);
                        }
                }
        }
        cout << d[k][1] << "\n";
}

int main()
{
        int T;
        cin >> T;
        for(int i = 1; i <= T; i++){
                cout << "Case #" << i << ": ";
                solve();
        }
}
