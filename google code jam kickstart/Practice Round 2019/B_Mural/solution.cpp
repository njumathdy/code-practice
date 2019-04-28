/*******************
Thanh wants to paint a wonderful mural on a wall that is N sections long. 
Each section of the wall has a beauty score, which indicates how beautiful it will look if it is painted. 
Unfortunately, the wall is starting to crumble due to a recent flood, so he will need to work fast!

At the beginning of each day, Thanh will paint one of the sections of the wall. 
On the first day, he is free to paint any section he likes. 
On each subsequent day, he must paint a new section that is next to a section he has already painted, since he does not want to split up the mural.

At the end of each day, one section of the wall will be destroyed. 
It is always a section of wall that is adjacent to only one other section and is unpainted (Thanh is using a waterproof paint, so painted sections can't be destroyed).

The total beauty of Thanh's mural will be equal to the sum of the beauty scores of the sections he has painted. 
Thanh would like to guarantee that, no matter how the wall is destroyed, he can still achieve a total beauty of at least B. 
What's the maximum value of B for which he can make this guarantee?
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

int T;

void solve(int j, int n, string score) {
    int res = 0;
    int sum = 0;
    int l;
    if(n % 2 == 0)
        l = n / 2;
    else
        l = n / 2 + 1;
    
    for(int i = 0; i < l; i++)
        sum += score[i] - '0';
    res = sum;
    for(int i = 1; i <= n - l ; i++) {
        sum = sum + (score[l+i-1] - '0') - (score[i-1] - '0');
        res = max(res, sum);
    }
    cout << "Case #" << j << ": " << res << endl;
}

int main() {
    cin >> T;
    int n;
    string score;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        cin >> score;
        solve(i, n, score);
    }

    return 0;
}
