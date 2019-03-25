/*
ID: mg172101
LANG: C++11
PROG: sort3
*/

/*************************
 * 最佳方案十分清晰，因此可以采用遍历的方法。先考虑将1排好，具体方法是将数组中属于1的位置上的2和3分别和其他部分互换，
 * 首先考虑将1中的2和2中的1互换，将1中的3和3中的1互换。再考虑将1中的2与3中的1互换，将1中的3与2中的1互换。将1排好
 * 之后，再排2，当2排好之后，3自然也排好了。
 ************************/ 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int count1 = 0, count2 = 0, count3 = 0;
vector<int> v(1001, 0);

int main() {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    fin >> N;
    for(int i = 1; i <= N; i++) {
        fin >> v[i];
        if(v[i] == 1) count1++;
        if(v[i] == 2) count2++;
        if(v[i] == 3) count3++;
    }
    fin.close();
    if(count1 == N || count2 == N || count3 == N) {
        fout << 0 << endl;
        fout.close();
        return 0;
    }
    int a2 = 0, a3 = 0, b1 = 0, b3 = 0, c1 = 0, c2 = 0;
    for(int i = 1; i <= count1; i++) {
        if(v[i] == 2) a2++;
        if(v[i] == 3) a3++;
    }
    for(int i = count1+1; i <= count1+count2; i++) {
        if(v[i] == 1) b1++;
        if(v[i] == 3) b3++;
    }
    for(int i = count1+count2+1; i <= N; i++) {
        if(v[i] == 1) c1++;
        if(v[i] == 2) c2++;
    }
    int total = 0;
    if(a2 > 0) {
        if(b1 < a2) {
            total += b1;
            a2 -= b1;
            b1 = 0;
        } else {
            total += a2;
            b1 -= a2;
            a2 = 0;
        }
        if(a2 > 0) {
            total += 2 * a2;
            c1 -= a2;
            b3 -= a2;
            a2 = 0;
        }
    }
    if(a3 > 0) {
        if(c1 < a3) {
            total += c1;
            a3 -= c1;
            c1 = 0;
        } else {
            total += a3;
            c1 -= a3;
            a3 = 0;
        }
        if(a3 > 0) {
            total += 2 * a3;
            b1 -= a3;
            c2 -= a3;
            a3 = 0;
        }
    }
    if(b3 > 0) {
        total += b3;
    }
    fout << total << endl;
    
    fout.close();
    

    return 0;
}
