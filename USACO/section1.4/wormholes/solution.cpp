/*
ID: mg172101
LANG: C++11
PROG: wormhole
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
int N;
ll a[13], b[13]; // 两个数组分别储存每个点的横、纵坐标
int partner[13]; // 储存每个点的配对点
int next_on_right[13];

bool isCycleExist() {
    for(int i = 1; i <= N; i++) {
        int pos = i; //若存在一个cycle,则之多N步之后一定会重新开始
        for(int j = 0; j < N; j++) {
            pos = next_on_right[partner[pos]];
        }
        if(pos != 0) return 1;
    }
    // 检测完所有点之后均未发现cycle则返回false
    return 0;
}
int dfs() {
    int i, total=0;
    // 检查未配对的点
    for (i=1; i<=N; i++)
        if (partner[i] == 0) break;
 
    // 所有点均配对，检测是否存在cycle
    if (i > N) {
        if (isCycleExist()) return 1;
        else return 0;
    }
 
    // try pairing i with all possible other wormholes j
    for (int j=i+1; j<=N; j++)
        if (partner[j] == 0) {
            // try pairing i & j, let recursion continue to
            // generate the rest of the solution
            partner[i] = j; // 将i与j配对 
            partner[j] = i;
            total += dfs(); // 递归
            partner[i] = partner[j] = 0; // 重置，以便继续递归
        }
    return total;

} 

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> N;

    for(int i = 1; i <= N; i++) {
        fin >> a[i] >> b[i];
    }
    fin.close();
    //遍历找出每个点右边最近的平行点，并储存在next_on_right[]中
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(a[j] > a[i] && b[j] == b[i]) {
                if(next_on_right[i] == 0 || a[j] - a[i] < a[next_on_right[i]] - a[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }
    fout << dfs() << endl;


    return 0;
}
