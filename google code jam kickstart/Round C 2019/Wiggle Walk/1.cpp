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
int N, R, C;
int sr, sc;

void moveNorth(vector<int>& coord) {
    coord[0]--;
}

void moveSouth(vector<int>& coord) {
    coord[0]++;
}

void moveEast(vector<int>& coord) {
    coord[1]++;
}

void moveWest(vector<int>& coord) {
    coord[1]--;
}

void solve(vector<vector<bool> >& flag, vector<int>& coord, string& s) {
    flag[coord[0]][coord[1]] = true;
    for(int i = 0; i < N; i++) {
        if(s[i] == 'N') {
            do {
                moveNorth(coord);
            } while(flag[coord[0]][coord[1]] == true);
            flag[coord[0]][coord[1]] = true;
        } else if(s[i] == 'S') {
            do {
                moveSouth(coord);
            } while(flag[coord[0]][coord[1]] == true);
            flag[coord[0]][coord[1]] = true;
        } else if(s[i] == 'E') {
            do {
                moveEast(coord);
            } while(flag[coord[0]][coord[1]] == true);
            flag[coord[0]][coord[1]] = true;
        } else {
            do {
                moveWest(coord);
            } while(flag[coord[0]][coord[1]] == true);
            flag[coord[0]][coord[1]] = true;
        }
    }
}

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        string instrcution;
        cin >> N >> R >> C >> sr >> sc;
        cin >> instrcution;
        vector<int> coord = {sr, sc};
        vector<vector<bool> > flag(R+1, vector<bool>(C+1, false));
        solve(flag, coord, instrcution);
        cout << "Case #" << i << ": " << coord[0] << " "  << coord[1]
        << endl;
    }

    return 0;
}
