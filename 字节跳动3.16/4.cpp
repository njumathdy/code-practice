/*******************
 * 本题代码不长，但是做题时一直没有想到对长度做二分搜索这个角度上来，没有抓住重点。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;
vector<double> length;

inline bool check(double l) {
    int count = 0;
    for(int i = n - 1; i >= 0 && length[i] >= l; --i) {
        count += floor(length[i] / l);
    }
    return count >= m;
}

double solve(int m) {
    double l = 0.f, r = length[n-1] + 1.f;
    while(r - l > 1e-3) {
        double k = (l+r) / 2;
        if(check(k))
            l = k;
        else 
            r = k - 0.001;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> t;
        length.push_back((double)t);
    }
    sort(length.begin(), length.end());
    printf("%.2lf", solve(m));

    return 0;
}