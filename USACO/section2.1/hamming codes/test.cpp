/*******************
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

void test(int x[5]) {
    char a[5][6];

    cout << sizeof(x) << endl;
    cout << sizeof(x[0]) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(a+0) << endl;
    cout << &a << " " << sizeof(&a) << endl;
}

string transformToBaseB(int i, int b) {
    string s = "";
    int temp, j = 0;
    while(i > 0) {
        temp = i % b;
        i /= b;
        s += char(temp+'0');
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    // int x[5];
    // test(x);
    string s = transformToBaseB(17612864, 2);
    cout << s << endl;


    return 0;
    
}
