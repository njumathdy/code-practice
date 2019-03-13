/*******************
*******************/
#include <exception>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[51], b[51];
int res = 0;
int minSum(int* a, int* b) {
    if(n == 0) 
        return 0;

    sort(a, a+n);
    sort(b, b+n);

    for(int i = 0; i < n; i++) {
        res += a[i] * b[n-1-i];
    }

    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    res = minSum(a, b);
    cout << res << endl;

    return 0;
}