/*******************
 * 图的m着色问题
 * 主要思想是用回溯法进行搜索。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>

using namespace std;

int n, k, m, x, y; // n，k，m分别是顶点个数，边的数量以及可用颜色的数量
int res = 0; // 所有可行染色方案的数目
// matrix是图的表示矩阵，colors[i][j]表示与i相连的点有多少个是颜色j
int matrix[1001][1001], colors[1001][1001];
int color[1001];

// 逐点搜索
void dfs(int v) {
    int i,j;
    // 如果所有的点都遍历且未中途返回，则说明找到一种可行方案，将res递增
    if(v == n+1) {
        res++;
        // cout << res << endl;
        for(i = 1; i <= n; i++) {
            cout << color[i] << "\t";
        }
        cout << endl;
        return;
    }

    for(i = 1; i <= m; i++) { // 枚举所有m种颜色
        if(!colors[v][i]) { // 如果这个点周围没有i这种颜色，就说明这个点可以染成颜色i
            color[v] = i;
            for(j = 1; j <= n; j++) {
                if(matrix[v][j]) {
                    colors[j][i]++;
                } // 将所有与v相邻的点对于颜色i都加1
            }
            dfs(v+1); // 搜索下一个点
            // 回溯一步，以为了下次搜索
            // color[v] = 0;
            for(j = 1; j <= n; j++) {
                if(matrix[v][j]) {
                    colors[j][i]--;
                }        
            }
        }
    }

    return;
}

int main() {
    cin >> n >> k >> m;
    for(int i = 0; i <= n ; i++)    
        color[i] = 0;
    for(int i = 1; i <= k; i++) {
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    dfs(1);
    cout << res << endl;

    return 0;
}