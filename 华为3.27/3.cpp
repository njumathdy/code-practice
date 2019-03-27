/*******************
 * m*n矩阵，0或1，每次可以画一条直线，将该直线上的1变为0，至少需要多少次可以将1全部变为0。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>

using namespace std;

int a[40][50];
int N;


int main() {
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 50; j++) {
            a[i][j] = 0;
        }
    }

    cin >> N;
    int x, y;
    for(int i = 1; i <= N; i++) {
        cin >> x >> y;
        a[x][y] = 1;
    }

    int count = 0;


    return 0;
}