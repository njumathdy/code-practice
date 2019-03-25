/*
ID: mg172101
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

string a, b;
map<char, int> m;
int i1 = 1, i2 = 1;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t = 1;
    for(auto s : c) {
        m[s] = t++;
    }
    fin >> a >> b;
    for(auto s : a) {
        i1 = i1 * m[s];
    }
    for(auto s : b) {
        i2 = i2 * m[s];
    }
    if(i1 % 47 == i2 % 47) {
        fout << "GO" << endl;
    }
    else {
        fout << "STAY" << endl;
    }

    return 0;
}
