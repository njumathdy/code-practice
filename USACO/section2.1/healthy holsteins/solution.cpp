/*
ID: mg172101
LANG: C++11
PROG: holstein
*/

/*****************************
*****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int V, G, total = 15;
int v[26], sum[26]; //v表示题目中维生素的要求，sum用来表示我们的结果
int scoop[17][26];
bool temp[16] = {false}, checked[16] = {false};

//深度搜索，level表示scoop的编号，total表示需要的scoop的数量
void dfs(int level, int total1) {
    bool f = false; //是否符合要求，false表示符合，true表示不符合
    //按照这种写法，在dfs(n+1, ...)中才会检查dfs(n, ...)时的操作
    if(level > G+1) return; //超出限制，无效
    for(int i = 1; i <= V; i++) {
        if(sum[i] < v[i]) { //不满足要求
            f = true;
            break;
        }
    }
    if(total1 < total && !f) {
        total = total1;
        for(int i = 1; i <= G; i++) {
            checked[i] = temp[i];
        }
        return;
    }
    //每种scoop有两种情况，选或不选
    //选择
    total1++;
    temp[level] = true;
    for(int i = 1; i <= V; i++) {
        sum[i] += scoop[level][i];
    }
    dfs(level+1, total1);
    //不选
    total1--;
    temp[level] = false;
    for(int i = 1; i <= V; i++) {
        sum[i] -= scoop[level][i];
    }
    dfs(level+1, total1);
}

int main() {
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    fin >> V;
    int i, j;
    for(i = 1; i <= V; i++) {
        fin >> v[i];
    }
    fin >> G;
    for(i = 1; i <= G; i++) {
        for(j = 1; j <= V; j++) {
            fin >> scoop[i][j];
        }
    }
    fin.close();

    dfs(1, 0);
    fout << total << " ";
    for(i = 1; i <= G; i++) {
        if(checked[i]) {
            total--;
            if(total > 0) fout << i << " ";
            else fout << i << endl;
        }
    }
    fout.close();



    return 0;
}
