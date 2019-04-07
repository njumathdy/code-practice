/*******************
AC
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int x, y;

int gcd(int a, int b) {
    if(b > a)
        swap(a, b);
    if(a % b == 0)
        return b;
    else {
        return gcd(b, a%b);
    }   
}

int solve(int row, int column) {
    if(row == column)
        return row;
    if(column > row)
        return solve(column, row);
    int gcd1 = gcd(row, column);
    row = row / gcd1;
    column = column / gcd1;
    int res;
    res = (row+column-1);
    res *= gcd1;
    return res;
}

int main() {
    cin >> x >> y;
    int res = solve(x+1, y+1);
    cout << res << endl;
    return 0;
}