/*
ID: mg172101
LANG: C++11
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isContain(string s, char a) {
    string::size_type i = s.find(a);
    if(i != string::npos) return true;
    else return false;
}
char pos(string s, int i) {
    int l = s.length();
    if(i >= 0) return s[i % s.length()];
    else return s[i + l];
}
int maxLength1(string s, int i) {
    int length = 0, j = 0;
    while(pos(s, i+j) == 'w') {
        length++;
        j++;
    }
    char r = pos(s, i+j);
    for(; j < s.length(); j++) {
        if(pos(s, i+j) == 'w' || pos(s, i+j) == r) length++;
        else break; 
    }
    return length;
}
int maxLength2(string s, int i) {
    int length = 0, j = 0;
    while(pos(s, i-1-j) == 'w') {
        length++;
        j++;
    }
    char r = pos(s, i-1-j);
    for(; j < s.length(); j++) {
        if(pos(s, i-1-j) == 'w' || pos(s, i-1-j) == r) length++;
        else break;
    }
    return length;
}

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int T;
    string s;

    fin >> T;
    fin >> s;

    if(!isContain(s, 'r') || !isContain(s, 'b')) {
        fout << T << endl;
        return 0;
    }

    int length = 0, temp = 0;
    for(int i = 0; i < s.length(); i++) {
        temp = min(maxLength1(s, i) + maxLength2(s, i), T);
        length = max(temp, length);
    }

    fout << length << endl;

    return 0;

}