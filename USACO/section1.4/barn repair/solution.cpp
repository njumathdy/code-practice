/*
ID: mg172101
LANG: C++11
PROG: barn1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int M, S, C;
    fin >> M >> S >> C;
    //考虑边际情况
    if(M >= C) {
        fout << C << endl;
        return 0;
    }

    int cow[210], diff[C];

    for(int i = 0; i < C; i++) {
        fin >> cow[i];
    }
    sort(cow, cow+C);
    for(int j = 0; j < C-1; j++) {
        diff[j] = cow[j+1] - cow[j];
    }

    int length = cow[C-1] - cow[0] + 1;

    sort(diff, diff+C-1, [](const int a, const int b) { return a > b;});

    int i = 0;
    while(M > 1) {
        length -= (diff[i]-1);
        i++;
        M--;
    }
    fout << length << endl;
    

    return 0;
}
