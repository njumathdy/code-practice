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

string s;
int ans = 0;

void solve(string s) {
    int n = s.size(), i;
    for(i = 0; i < n; i++) {
        if(s[i] == '0')
            break;
    }
    if(i == n)
        ans = n;
    else {
        int j = (i+1) % n;
        while(j != i) {
            if(s[j] == '0') {
                j = (j+1) % n;
            } else {
                int k = 0;
                while(s[(j+k)%n] == '1') {
                    k++;
                }
                j = (j+k) % n;
                ans = max(ans, k);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve(s);

    return 0;
}