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

int n, m, q;
int l, r;
vector<int> square;

int solve(vector<int> s, int l, int r) {
    if(s[l] == -1)
        return 0;

    if(l == r) {
        if(s[l] == -1 || s[l] == -2) {
            return 0;
        } else {
            return s[l];
        }
    }

    int res = 0;
    int i = l;
    bool dir = false;
    bool right = true;
    while(true) {
        if(i < l || i > r)
            break;
        
        if(s[i] == -3) {
            if(right) i++;
            else i--;
            continue;
        }

        if(s[i] == -1 || s[i] == -2) {
            if(dir) {
                if(s[i] == -1) right = false;
                else right = true;
                s[i] = -3;
                dir = false;
            } else {
                dir = true;
                if(s[i] == -1) 
                    right = false;
                else 
                    right = true;
            }
        } else if(s[i] == 0){
            // dir = false;
            s[i] = -3;
        } else {
            dir = false;
            res += s[i];
            s[i]--;
        }

        if(right) {
            i++;
        } else
            i--;
    }

    return res;
}

int main() {
    cin >> n >> m >> q;

    string temp;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(temp == "<") 
            square.push_back(-1);
        else if(temp == ">")
            square.push_back(-2);
        else
            square.push_back(stoi(temp));
    }

    for(int i = 1; i <= q; i++) {
        cin >> l >> r;
        cout << solve(square, l-1, r-1) << endl;
    }
    
    return 0;
}