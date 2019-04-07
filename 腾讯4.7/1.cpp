/*******************
AC
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N, K;
int ans = 0;

void solve(int n, int K) {
    if(n <= 2) {
        cout << n << endl;
        return;
    }
    int k = 1, count = 0;
    while(n >= k) {
        k *= 2;
        count++;
    }
    if(K >= count - 1) {
        if(n * 2 == k)
            ans = count;
        else
            ans = count+1;   
    } else {
        ans += K;
        for(int i = 1; i <= K; i++) {
            if(n % 2 == 0)
                n /= 2;
            else
                n = n / 2 + 1;    
        }
        ans += n;
    }
    cout << ans << endl;      
}

int main() {
    cin >> N >> K;
    solve(N, K);

    return 0;
}