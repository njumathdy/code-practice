/*
ID: mg172101
LANG: C++11
PROG: frac1
*/

/*************************
 * 简单的枚举并排序即可
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

int gcd(int a, int b) {
    int r = a % b;
    while(r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

class fraction {
    public:
        int denominator;
        int numerator;
};

bool fracCompare(fraction &a, fraction &b) {
    return a.numerator * b.denominator < a.denominator * b.numerator;
}

int N;
vector<fraction> v;

int main() {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    fin >> N;

    for(int i = 1; i < N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(gcd(j, i) == 1) {
                fraction temp;
                temp.numerator = i;
                temp.denominator = j;
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end(), fracCompare);
    fout << 0 << "/" << 1 << endl;
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        fout << iter->numerator << "/" << iter->denominator << endl;
    }
    fout << 1 << "/" << 1 << endl;

    fin.close();
    fout.close();

    return 0;
}
