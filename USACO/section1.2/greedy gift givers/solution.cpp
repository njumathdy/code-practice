/*
ID: mg172101
LANG: C++
PROG: gift1 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int T, N, a, b;
string name;
map<string, int> m;
vector<string> namev(11, ""), namev1(11, "");

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    fin >> T;
    for(int i=1; i <= T; i++) {
        fin >> name;
        namev1[i] = name;
        m[name] = 0;
    }
    for(int i=1; i <= T; i++) {
        fin >> name;
        fin >> a >> b;
        if(a == 0) continue;
        if(b == 0) m[name] += a;
        else {
            m[name] = m[name] - a / b * b;
            namev.clear();
            for(int j=1; j<= b; j++) {
                fin >> namev[j];
                m[namev[j]] += (a / b);
            }
        }
    }
    for(int i = 1; i <= T; i++) {
        fout << namev1[i] << " " << m[namev1[i]] << endl;
    }



    return 0;
}
