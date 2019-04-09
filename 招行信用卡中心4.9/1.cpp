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

int n, m;
vector<int> people;

void solve(vector<int>& vec, int m) {
    int maxc = vec[0], minc;
    int l = vec.size();
    for(int i = 0; i < l; i++) {
        if(vec[i] > maxc)
            maxc = vec[i];
    }
    int sum = 0;
    for(int i = 0; i < l; i++) {
        sum += maxc - vec[i];
    }
    if(sum >= m)
        minc = maxc;
    else {
        minc = maxc;
        int diff = m - sum;
        if(diff % n == 0)
            minc += diff / n;
        else
            minc += diff / n + 1;   
    }
    cout << minc << " " << maxc+m << endl;

}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        people.push_back(t);
    }
    solve(people, m);

    return 0;
}