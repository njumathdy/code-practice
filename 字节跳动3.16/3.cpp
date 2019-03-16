/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, t;
vector<pair<int, int> > a;
vector<int> scores, v;

// 辅助函数，用来返回左边或者右边的下标
inline int left(int index) {
    if(index == 0) 
        return m-1;
    else 
        return index-1;
}

inline int right(int index) {
    if(index == m-1)
        return 0;
    else 
        return index+1;
}

inline int get_next(int index, int direction) {
    if(direction == 1)
        return right(index);
    else 
        return left(index);
}

// 核心函数，沿着一个方向一直找到递增序列的倒数第二个数。
void solve(int start, int direction) {
    int index = start, count = 1;
    int next = get_next(index, direction);
    v[start] = 0;
    // 下一个位置的分数不小于该位置的数且还未分配礼物
    while(scores[index] <= scores[next] && v[index] == 0) {
        v[index] = count;
        if(scores[index] < scores[next])
            count += 1;
        else 
            count = 1;
        index = next;
        next = get_next(index, direction);
    }
    v[start] = 1;
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> m;
        v.clear(); scores.clear(); a.clear();
        for(int j = 0; j < m; j++) {
            cin >> t;
            v.push_back(0);
            scores.push_back(t);
            a.push_back(make_pair(t, i));
        }
        sort(a.begin(), a.end()); // 排序，每次考察最小的分数的位置分配的奖品个数
        for(int j = 1; j < n; j++) {
            int index = a[i].second;
            if(v[index] != 0) // 该位置已分配奖品，跳出本次循环
                continue;
            // 两边都已分配好奖品，该位置是其中较大的那个再加1
            if(v[left(index)] != 0 && v[right(index)] != 0) 
                v[index] = max(v[left(index)], v[right(index)]) + 1;
            if(v[left(index)] == 0) 
                solve(index, -1);
            if(v[right(index)] == 0)
                solve(index, 1);
        }
        int res = 0;
        for(int j = 0; j < m; j++)
            res += v[i];

        cout << res << endl;
    }
    
    return 0;
}