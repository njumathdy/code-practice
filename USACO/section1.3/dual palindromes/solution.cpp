/*
ID: mg172101
LANG: C++11
PROG: dualpal
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
bool isDualPal(int n) {
    int count = 0;
    for(int i = 2; i <= 10; i++) {
        string s = transformToBaseB(n, i);
        if(isPalindromic(s)) {
            count++;
        }
        if(count > 1) {
            return true;
        }
    }
    return false;
}
int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int N, S;
    fin >> N >> S;
    S++;
    
    while(N) {
        if(isDualPal(S)) {
            fout << S << endl;
            N--;
        }
        S++;
    }

    
    return 0;
}
