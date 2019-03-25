/*
ID: mg172101
LANG: C++11
PROG: castle
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int roomN; //房间个数
int room[51][51]; //每个点所属房间编号
int sizeR[2501]; //房间大小
int maxS = 0; //最大的房间面积
int check[51][51]; //该房间是否检查过
int wall[51][51][4]; //是否有墙

void dfs(int i, int j) {
    if(room[i][j] == roomN) return;
    check[i][j] = 1;
    sizeR[roomN]++;
    room[i][j] = roomN;
    if(!wall[i][j][0]) dfs(i, j-1);
    if(!wall[i][j][1]) dfs(i-1, j);
    if(!wall[i][j][2]) dfs(i, j+1);
    if(!wall[i][j][3]) dfs(i+1, j);
}

int main() {
    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> M >> N;

    int temp;
    int i, j, k;
    
    for(i=1; i<=N; i++) {
        for(j=1; j<=M;j++) {
            fin >> temp;
            for(k=0; k<4; k++) {
                wall[i][j][k] = (temp >> k) & 1;
            }
        }
    }
    for(i=1; i<=N; i++) {
        for(j=1; j<=M; j++) {
            if(!check[i][j]) {
                roomN++;
                dfs(i, j);
                maxS = max(maxS, sizeR[roomN]);
            }
        }
    }
    fout << roomN << endl << maxS << endl;

    maxS = 0;
    int roomA, roomB, roomC;
    int ans_x, ans_y;
    char dir;
    for(i=1; i<=M; i++) {
        for(j=N; j>=1; j--) {
            roomA = room[j][i];
            roomB = room[j-1][i];
            roomC = room[j][i+1];
            if(j > 1 && wall[j][i][1] && roomA != roomB && sizeR[roomA]+sizeR[roomB] > maxS) {
                maxS = sizeR[roomA] + sizeR[roomB];
                ans_x = j;
                ans_y = i;
                dir = 'N';
            } else if(i < M && wall[j][i][2] && roomA != roomC && sizeR[roomA] + sizeR[roomC] > maxS) {
                maxS = sizeR[roomA] + sizeR[roomC];
                ans_x = j;
                ans_y = i;
                dir = 'E';
            }
        }
    }
    fout << maxS << endl << ans_x << " " << ans_y << " " << dir << endl;

    return 0;
}
