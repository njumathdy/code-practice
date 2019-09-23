/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N, M;
vector<int> direction(800, -1);
vector<vector<int> > graph(800, vector<int>(800, 0));

struct Triangle {
    vector<int> ver;

    Triangle() {
        ver = vector<int>(3, 0);
    }
};
vector<Triangle> tri;

bool is_connect(Triangle& t1, Triangle& t2) {
    // cout << "is connext ..." << endl;
    int count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(t1.ver[i] == t2.ver[j]) count++;
        }
    }

    return count == 2;
}

void build_graph() {
    for(int i = 0; i < M-1; i++) {
        for(int j = i+1; j < M; j++) {
            if(i < M && j < M && is_connect(tri[i], tri[j])) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    return;
}

bool is_same_direction(Triangle& t1, Triangle& t2) {
    for(int i = 0; i < 3; i++) {
        int a = t1.ver[i], b = t1.ver[(i+1)%3], c = t1.ver[(i+2)%3];
        if((a == t2.ver[0] && b == t2.ver[1]) || 
          (a == t2.ver[0] && c == t2.ver[2]) || 
          (b == t2.ver[1] && c == t2.ver[2]))
            return false;
    }
    return true;
}

void change_direction(Triangle& t) {
    reverse(t.ver.begin(), t.ver.end());
}

void find_min_ver(Triangle& t) {
    if(t.ver[0] < t.ver[1] && t.ver[0] < t.ver[2]) {
        cout << t.ver[0] << ' ' << t.ver[1] << ' ' << t.ver[2] << endl;
        return;
    } else if(t.ver[1] < t.ver[0] && t.ver[1] < t.ver[2]) {
        cout << t.ver[1] << ' ' << t.ver[2] << ' ' << t.ver[0] << endl;
        return;
    } else {
        cout << t.ver[2] << ' ' << t.ver[0] << ' ' << t.ver[1] << endl;
        return;
    }
}

void solve() {
    build_graph();
    // cout << "build graph success!" << endl;
    direction[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 1 && direction[j] < 0) {
                if(is_same_direction(tri[i], tri[j])) {
                    direction[j] = direction[i];
                } else direction[j] = 1 - direction[i];

                q.push(j);
            }
        }
    }
    
    for(int i = 0; i < M; i++) {
        if(direction[i] == 0) find_min_ver(tri[i]);
        else {
            change_direction(tri[i]);
            find_min_ver(tri[i]);
        }
    }
    
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        Triangle t;
        cin >> t.ver[0] >> t.ver[1] >> t.ver[2];
        tri.push_back(t);
    }
    
    solve();

    return 0;
}