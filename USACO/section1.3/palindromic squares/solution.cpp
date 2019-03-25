/*
ID: mg172101
LANG: C++11
PROG: palsquare
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string transformToBaseB(int N, int B) {
    string ans = "";
    while(N) {
        int rem = N%B;
        if(rem < 10) {
            ans += char(rem + '0');
        } else {
            ans += char(rem - 10 + 'A');
        }
        N = N / B;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool isPalindromic(string s) {
    int l = s.size();
    for(int i = 0; i < l / 2; i++) {
        if(s[i] != s[l-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int b;
    fin >> b;
    for(int i = 1; i <= 300; i++) {
        if(isPalindromic(transformToBaseB(i*i, b))) {
            fout << transformToBaseB(i, b) << " " << transformToBaseB(i*i, b) << endl;
        }
    }

    return 0;
}
