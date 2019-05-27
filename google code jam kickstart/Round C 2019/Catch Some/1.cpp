/*******************
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

int T;
int N, K;

struct Dog {
    int pos;
    int col;
};

vector<Dog> dog(1005);

bool cmp(Dog dog1, Dog dog2) {
    return dog1.pos < dog2.pos;
}

int main() {
    for(int i = 1; i <= T; i++) {
        cin >> N >> K;
        for(int j = 0; j < N; j++) {
            cin >> dog[j].pos;
        }
        for(int j = 0; j < N; j++) {
            cin >> dog[j].col;
        }
        cout << 'Case #' << i << ': ' << endl;
    }

    return 0;
}
