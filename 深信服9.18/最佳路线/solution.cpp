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

char d1, d2;

void solve() {
    if(d1 == 'A' && d2 == 'B') {
        cout << 12 << endl;
        cout << d1 << ' ' << d2 << endl;
        return;
    }
    if(d1 == 'A' && d2 == 'C') {
        cout << 22 << endl;
        cout << 'A' << ' ' << 'B' << 'C' << endl;       
    }
    if(d1 == 'A' && d2 == 'D') {
        cout << 25 << endl;
        cout << 'A' << ' ' << 'B' << ' ' << "C " << 'D' << endl;      
    }
    if(d1 == 'A' && d2 == 'E') {
        cout << 27 << endl;
        cout << "A B C E" << endl;     
    }
    if(d1 == 'A' && d2 == 'F') {
        cout << 19 << endl;
        cout << "A B F" << endl;  
    }
    if(d1 == 'B' && d2 == 'A') {
        cout << 23 << endl;
        cout << "B F A" << endl;
    }
    if(d1 == 'B' && d2 == 'C') {
        cout << 10 << endl;
        cout << "B C" << endl;
    }
    if(d1 == 'B' && d2 == 'D') {
        cout << 13 << endl;
        cout << "B C D" << endl;
    }
    if(d1 == 'B' && d2 == 'E') {
        cout << 15 << endl;
        cout << "B C E" << endl;
    }
    if(d1 == 'B' && d2 == 'F') {
        cout << 16 << endl;
        cout << "B C F" << endl;
    }
    if(d1 == 'C' && d2 == 'A') {
        cout << 22 << endl;
        cout << "C F A" << endl;
    }
    if(d1 == 'C' && d2 == 'B') {
        cout << 34 << endl;
        cout << "C F A B" << endl;
    }
    if(d1 == 'C' && d2 == 'D') {
        cout << 3 << endl;
        cout << "C D" << endl;
    }
    if(d1 == 'C' && d2 == 'E') {
        cout << 5 << endl;
        cout << "C E" << endl;
    }
    if(d1 == 'C' && d2 == 'F') {
        cout << 6 << endl;
        cout << "C F" << endl;
    }

    return;
}

int main() {
    cin >> d1 >> d2;
    solve();

    return 0;
}