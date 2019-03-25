/*
ID: mg172101
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<char> > rotation90(vector<vector<char> > pattern) {
    vector<vector<char> > pattern1 = pattern;
    int n = pattern.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pattern1[j][n-1-i] = pattern[i][j];
        }
    }
    return pattern1;
}
vector<vector<char> > rotation180(vector<vector<char> > pattern) {
    vector<vector<char> > pattern1 = pattern;
    int n = pattern.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pattern1[i][j] = pattern[n-1-i][n-1-j];
        }
    }
    return pattern1;
}
vector<vector<char> > rotation270(vector<vector<char> > pattern) {
    vector<vector<char> > pattern1 = pattern;
    int n = pattern.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pattern1[n-1-j][i] = pattern[i][j];
        }
    }
    return pattern1;
}
vector<vector<char> > reflection(vector<vector<char> > pattern) {
    vector<vector<char> > pattern1 = pattern;
    int n = pattern.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= (n-1)/2; j++) {
            char temp = pattern1[i][j];
            pattern1[i][j] = pattern[i][n-1-j];
            pattern1[i][n-1-j] = temp;
        }
    }
    return pattern1;
}
int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int N;
    fin >> N;
    vector<vector<char> > pattern, pattern1;
    pattern.reserve(N);
    pattern1.reserve(N);
    char c;
    for(int i = 0; i < N; i++) {
        vector<char> v(N, ' ');
        pattern.push_back(v);
        for(int j = 0; j < N; j++) {
            fin >> c;
            pattern[i][j] = c;
        }
    }
    for(int i = 0; i < N; i++) {
        vector<char> v(N, ' ');
        pattern1.push_back(v);
        for(int j = 0; j < N; j++) {
            fin >> c;
            pattern1[i][j] = c;
        }
    }
    if(pattern1 == rotation90(pattern)) {
        fout << 1 << endl;
        return 0;
    } 
    else if (pattern1 == rotation180(pattern))
    {
        fout << 2 << endl;
        return 0;
    }
    else if (pattern1 == rotation270(pattern)) {
        fout << 3 << endl;
        return 0;
    }
    else if (pattern1 == reflection(pattern)) {
        fout << 4 << endl;
        return 0;
    }
    else if (pattern1 == rotation90(reflection(pattern)) || pattern1 == rotation180(reflection(pattern)) || pattern1 == rotation270(reflection(pattern))) {
        fout << 5 << endl;
        return 0;
    }
    else if (pattern1 == pattern) {
        fout << 6 << endl;
        return 0;
    } else fout << 7 << endl;
    

    return 0;
}
