/*
ID: mg172101
LANG: C++11
PROG: milk3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int A, B, C;
bool done[21][21] = {false}, ans[22] = {false};

void dfs(int a, int b) {
    if(done[a][b]) return;
    done[a][b] = true;
    if(a == 0) ans[C-a-b] = true;
    //C to B
    if(C-a-b > B-b) dfs(a, B);
    else dfs(a, b+(C-a-b));
    //C to A
    if(C-a-b > A-a) dfs(A, b);
    else dfs(a+(C-a-b), b);
    //A to B
    if(a > B-b) dfs(a-(B-b), B);
    else dfs(0, b+a);
    //A to C
    if(a > C-(C-a-b)) dfs(a-C+(C-a-b), b);
    else dfs(0, b);
    //B to A
    if(b > A-a) dfs(A, b-(A-a));
    else dfs(a+b, 0);
    //B to C
    if(b > C-(C-a-b)) dfs(a, b-C+(C-a-b));
    else dfs(a, 0);
}

int main() {
    fin >> A >> B >> C;
    dfs(0, 0);
    bool flag = true;
    for(int i = 0; i < 22; i++) {
        if(ans[i]) {
            if(!flag) fout << " ";
            fout << i;
            flag = false;
        }   
    }
    fout << endl;

    return 0;
}
