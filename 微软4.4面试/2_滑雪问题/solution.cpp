/*******************
 * 滑雪问题：给定一个二维数组，每个位置是一个非负整数，表示该位置的高度，当目前的位置严格大于相邻位置时，
 * 可以从该位置滑到下一个位置，求最长的滑行距离。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100 + 5;

int m, n;
vector<vector<int> > matrix(maxn, vector<int>(maxn, 0));
vector<vector<int> > dp(maxn, vector<int>(maxn, 0));
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, 1, -1};

int dfs(int i, int j) {
    int& ans = dp[i][j];
    if(ans > 0)
        return ans;
    ans = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + x[k];
        int y = j + y[k];
        if(x < 0 || x > m-1 || y < 0 || y > n-1)
            continue;
        if(matrix[x][y] < matrix[i][j])
            ans = max(ans, dfs(x, y) + 1);
    }
    return ans;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i++) 
        for(int j = 0; i < n; i++)
            cin >> matrix[i][j];

    int maxd = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            maxd = max(maxd, dfs(i,j));
    cout << maxd << endl;

    return 0;
}