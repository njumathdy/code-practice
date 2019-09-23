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

void solution(int N, int M)
{
	vector<bool> flag(N, true);
    vector<int> res;
    int i = 1, j = 0;
    while(true) {
        if(i % M == 0) {
            res.push_back(j);
            cout << j+1 << ' ';
            if(res.size() == N) break;
            flag[j] = false;
        }
        i++;
        j = (j+1) % N;
        while(flag[j % N] == false) {
            j = (j+1) % N; 
        }
    }

    cout << endl;
    return;
}

int main() {
    int N = 6;
    int M = 3;
    solution(N, M);

    return 0;
}