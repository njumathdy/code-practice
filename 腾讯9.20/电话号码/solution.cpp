/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int t;

int main() {
    cin >> t;

    int n;
    string s;

    for(int i = 1; i <= t; i++) {
        cin >> n >> s;
        if(n < 11) {
            cout << "NO" << endl;
        } else if(n == 11) {
            if(s[0] == '8') cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            bool flag = false;
            for(int i = 0; i <= n-11; i++) {
                if(s[i] == '8') {
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}