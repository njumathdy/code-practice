/*
ID: mg172101
LANG: C++11
PROG: crypt1
*/

/*
暴力搜索，分情况讨论即可
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isIn(int temp, vector<int> vInt) {
    int l = vInt.size();
    for(int i = 0; i < l; i++) {
        if(temp == vInt[i]) {
            return true;
        }
    }
    return false;
}
int isFeasible(const vector<int> &a, const vector<int> &b, const vector<int> &num) {
    int d[4] = {1000, 100, 10, 1};
    int num1 = a[0] * 100 + a[1] * 10 + a[2];
    int res = num1 * (b[0] * 10 + b[1]), res1 = num1 * b[0], res2 = num1 * b[1];
    if(res1 > 999) return 0;
    if(res2 > 999) return 0;
    if(res > 9999) return 0;
    for(int i = 1; i < 4; i++) {
        int d0 = res1 / d[i], d1 = res2 / d[i];
        if(!isIn(d0, num) || !isIn(d1, num)) return 0;
        res1 = res1 % d[i];
        res2 = res2 % d[i];
    }
    for(int i = 0; i < 4; i++) {
        int d2 = res / d[i];
        if(!isIn(d2, num)) return 0;
        res = res % d[i];
    }
    return 1;

}
int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int N, count = 0;
    fin >> N;
    vector<int> num(N, 0), a(3, 0), b(2, 0);

    for(int i = 0; i < N; i++) {
        fin >> num[i];
        // cout << num[i] << endl;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                a[0] = num[i]; a[1] = num[j]; a[2] = num[k];
                for(int p = 0; p < N; p++) {
                    for(int q = 0; q < N; q++) {
                        b[0] = num[p]; b[1] = num[q];
                        count += isFeasible(a, b, num);
                    }
                }
            }
        }
    }
    fout << count << endl;

    return 0;
}
