/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>

using namespace std;

int n;

void reverse(string& s) {
    if(s[0] == '1')
        cout << s.substr(1, 8);
    else {
        int i = 1, j = s.size() - 1;
        while(j > i) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            j--;
            i++;
        }
        cout << s.substr(1, 8);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char t = '0';
        string s = "";
        for(int j = 0; j < 9; j++) {
            cin >> t;
            s += t;
        }
        reverse(s);
        if(i < n)
            cout << " ";
    }

    return 0;
}