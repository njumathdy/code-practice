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

const int maxn = 1005;
int n, m;
vector<vector<int> > matrix(maxn, vector<int>(maxn, 0));

void solve() {
    if(n < 3 || m < 3) {
        cout << 0 << endl;
        return;
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int count = 0;
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(matrix[i][j] != 1) continue;
            bool flag = true;
            for(int k = 0; k < 4; k++) {
                if(matrix[i+dx[k]][j+dy[k]] != 1) {
                    flag = false;
                    break;
                } 
            }
            if(flag) count++;
        }
    }
    cout << count << endl;
}

int main() {
    string t;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> t;
        for(int j = 0; j < m; j++) {
            matrix[i][j] = t[j] - '0';
        }
    }
    solve();

    return 0;
}