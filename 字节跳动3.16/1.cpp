/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>

using namespace std;

int res;

void solve(int& n) {
    while(n > 0) {
        if(n >= 64) {
            n -= 64;
            res++;
        } else if(n >= 16) {
            n -= 16;
            res++;
        } else if(n >= 4) {
            n -= 4;
            res++;
        } else {
            n -= 1;
            res++;
        }
    }
    printf("%d\n", res);
}

int main() {
    int N;
    cin >> N;
    N = 1024 - N;
    solve(N);

    return 0;
}