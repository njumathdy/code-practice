/*
ID: mg172101
LANG: C++11
PROG: hamming
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

int N, B, D;
int res[65];

int main() {
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    fin >> N >> B >> D;
    fin.close();

    int max = pow(2, B) - 1;
    res[1] = 0;
    int count = 1, i, j;

    for(i = 1; i <= max; i++) {
        for(j = 0; j <= count; j++) {
            int p = 0;
            for(int k = 0; k < B; k++) {
                int temp1 = i >> k & 1;
                int temp2 = res[j] >> k & 1;
                if(temp1 != temp2) p++;
                if(p >= D) break;
            }
            if(p < D) break;
            // 若j能达到count且未break，则说明i和之前找到的每个数的hamming distance都满足要求，将其加入结果数组
            else if(j == count) {
                res[++count] = i;
            }
        }
        if(count == N) break;
    }
    for(i = 1; i <= count; i++) {
        fout << res[i];
        if(i % 10 == 0 || i == count) {
            fout << endl;
        } else fout << " ";
    }
    fout.close();



    return 0;
}
