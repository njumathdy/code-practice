/*
ID: mg172101
LANG: C++11
PROG: ariprog
*/

/*******************
 * 本题可以用暴力搜索。题目给出了限制范围，可以遍历出所有的bisquare number，然后可以确定公差范围，在该范围内进行
 * 暴力搜索即可。
 *******************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int N, M;
int bs[125010] = {0}, bse[125010] = {0}, first[10010], difference[10010];
//bs: bisquare, bse: 表示是否是bisquare number， first: 首项, difference: 公差

void quickSort(int l, int r) {
    int x, y, i, j;
    i = l, j = r;
    x = bs[(i+j)/2];
    do {
        while(bs[i] < x) i++;
        while(bs[j] > x) j--;
        if(i <= j) {
            y = bs[i];
            bs[i] = bs[j];
            bs[j] = y;
            i++;
            j--;
        }
    } while(i <= j);
    if(i < r) quickSort(i, r);
    if(j > l) quickSort(l, j);
}
void solve() {
    int temp = -1, num; //temp是数组的指标
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= M; j++) {
            num = i*i + j*j; 
            if(!bse[num]) {
                temp++;
                bs[temp] = num;
            }
            bse[num] = 1;
        }
    }
    quickSort(0, temp);
    int max = 2 * M * M; //最大的bisquare
    int diffmax = 0, pointer = 0;
    bool existence = false;
    for(int i = 0; i <= temp - N + 1; i++) {
        diffmax = (max - bs[i]) / (N - 1);
        for(int j = 1; j <= diffmax; j++) {
            bool flag = true;
            for(int k = 1; k < N; k++) {
                if(!bse[bs[i]+k*j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                existence = true;
                pointer++;
                first[pointer] = bs[i];
                difference[pointer] = j;
            }
        }
    }
    if(existence) {
        for(int i = 1; i < pointer; i++) {
            for(int j = 1; j <= pointer - i; j++) {
                if(difference[j] > difference[j+1]) {
                    num = difference[j];
                    difference[j] = difference[j+1];
                    difference[j+1] = num;
                    num = first[j];
                    first[j] = first[j+1];
                    first[j+1] = num;
                }
            }
        }
        for(int i = 1; i <= pointer; i++) {
            fout << first[i] << " " << difference[i] << endl;
        }
        fout.close();
    } else {
        fout << "NONE" << endl;
        fout.close();
    }


}
// bool isSquare(int n) {
//     return floor(sqrt(n)) == sqrt(n);
// }
// bool isBisquare(int n) {
//     if(isSquare(n)) return 1;
//     for(int i = 1; i < sqrt(n); i++) {
//         if(isSquare(n - pow(i,2))) return 1;
//     }
//     return 0;
// }

int main() {
    fin >> N >> M;
    fin.close();

    solve();

    return 0;
}
