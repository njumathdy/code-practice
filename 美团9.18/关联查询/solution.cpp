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

string id, name0;
int t1, t2, t3;
string m1, m2, m3, name1; 

void solve() {

}

int main() {
    cin >> id >> name0;
    cin >> name1 >> m1 >> t1 >> m2 >> t2 >> m3 >> t3;

    cout << name0 << ' ';
    int i1, i2, i3;
    if(m1 == "01" && m2 == "02" && m3 == "03") {
        cout << t1 << ' ' << t2 << ' ' << t3 << ' ';
    } else if(m1 == "01" && m2 == "03" && m3 == "02") {
        cout << t1 << ' ' << t3 << ' ' << t2 << ' ';
    } else if(m1 == "02" && m2 == "01" && m3 == "03") {
        cout << t2 << ' ' << t1 << ' ' << t3 << ' ';
    } else if(m1 == "03" && m2 == "01" && m3 == "02") {
        cout << t2 << ' ' << t3 << ' ' << t1 << ' ';
    } else if(m3 == "01" && m2 == "02" && m1 == "03") {
        cout << t3 << ' ' << t2 << ' ' << t1 << ' ';
    } else {
        cout << t3 << ' ' << t1 << ' ' << t2 << ' ';
    }
    cout << t1+t2+t3 << endl;

    return 0;
}