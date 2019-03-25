/*
ID: mg172101
LANG: C++11
PROG: skidesign
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int N;
int height[1001];
int cost = INF;

void totalCost() {
    sort(height, height+N);
    for(int i = height[0]; i <= height[N-1]; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(height[j] - i > 17) {
                sum += (height[j] - i - 17) * (height[j] - i - 17);
            } else if (height[j] < i) {
                sum += (i - height[j]) * (i - height[j]);
            } else continue;
        }
        cost = min(cost, sum);
    }    
}

int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    fin >> N;
    for(int i = 0; i < N; i++) {
        fin >> height[i];
    }
    fin.close();

    totalCost();

    fout << cost << endl;
    fout.close();
    
    return 0;
}
