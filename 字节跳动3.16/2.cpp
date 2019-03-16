/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string transform1(string s) {
    string res = "";
    int i, j;
    int len = s.length();
    for(i = 0; i < len; i++) {
        res = res + s[i];
        for(j = i+1; j < len; j++) {
            if(s[j] != s[i]) 
                break;
        }
        if(j - i >= 3) 
            i = j-2;
    }
    return res;
}

string transform2(string s) {
    string res = "";
    int i, j;
    int len = s.length();
    for(i = 0; i < len; i++) {
        res = res + s[i];
        if(s[i+1] == s[i] && s[i+3] == s[i+2]) {
            res = res + s[i];
            i += 2;
        }
    }

    return res;
}

void transform(string s) {
    if(s.length() < 4) 
        cout << s << endl;

    string res = transform1(s);
    res = transform2(res);

    cout << res << endl;
}

int main() {
    string s;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        transform(s);
    }
    
    return 0;
}