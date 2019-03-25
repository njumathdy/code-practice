/*
ID: mg172101
LANG: C++11
PROG: numtri
*/

/*********************
 * 基本题，从底部向上扫描整个三角形，将值更新为局部的最优值，更新到最后就得到全局的最优值。
 * 感觉是一种递归的思想。
 ********************/ 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int R;
int num[1010][1010];

int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin >> R;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= i; j++) {
            fin >> num[i][j];
        }
    }
    for(int i = R-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            num[i][j] += max(num[i+1][j], num[i+1][j+1]);
        }
    }
    fout << num[1][1] << endl;
    fin.close();
    fout.close();

    return 0;
}
