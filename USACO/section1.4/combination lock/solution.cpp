/*
ID: mg172101
LANG: C++11
PROG: combo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool isLessThanTwo(const int a, const int b, const int N) {
    if(a - b <= 2 && a - b >= -2) return true;
    if(a == 1 && (b == N || b == N-1)) return true;
    if(a == 2 && b == N) return true;
    if(b == 1 && (a == N || a == N-1)) return true;
    if(b == 2 && a == N) return true;
    return false;
}
bool isCorrect(const vector<int> &a, const vector<int> &b, const int N) {
    for(int i = 0; i < 3; i++) {
        if(!isLessThanTwo(a[i], b[i], N)) return false;
    }
    return true;
}
int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    int N, count = 0;
    fin >> N;
    vector<int> a(3, 0), b(3, 0);
    for(int i = 0; i < 3; i++) {
        fin >> a[i];
    }
    for(int i = 0; i < 3; i++) {
        fin >> b[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                vector<int> c;
                c.push_back(i);
                c.push_back(j);
                c.push_back(k);
                if(isCorrect(a, c, N) || isCorrect(b, c, N)) {
                    count++;
                }
            }
        }
    }
    fout << count << endl;
    fout.close();

    return 0;
}
