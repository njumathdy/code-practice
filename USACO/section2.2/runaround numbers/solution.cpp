/*
ID: mg172101
LANG: C++11
PROG: runround
*/

/*****************************
Runaround numbers are integers with unique digits, none of which is zero (e.g., 81362) that also have an interesting property, exemplified by this demonstration:

If you start at the left digit (8 in our number) and count that number of digits to the right (wrapping back to the first digit when no digits on the right are available), you'll end up at a new digit (a number which does not end up at a new digit is not a Runaround Number). Consider: 8 1 3 6 2 which cycles through eight digits: 1 3 6 2 8 1 3 6 so the next digit is 6.
Repeat this cycle (this time for the six counts designed by the `6') and you should end on a new digit: 2 8 1 3 6 2, namely 2.
Repeat again (two digits this time): 8 1
Continue again (one digit this time): 3
One more time: 6 2 8 and you have ended up back where you started, after touching each digit once. If you don't end up back where you started after touching each digit once, your number is not a Runaround number.
Given a number M (that has anywhere from 1 through 9 digits), find and print the next runaround number higher than M, which will always fit into an unsigned long integer for the given test data.
*****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> nums;
vector<int> hash1(10, 0);
vector<int> hash2(10, 0);

ll n;
void init(ll n) {
    nums.clear();
    while(n > 0) {
        nums.push_back(n % 10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());
}

bool solve() {
    for(int i = 0; i < nums.size(); i++) {
        hash1[nums[i]]++;
        if(hash1[nums[i]] > 1 || nums[i] == 0)
            return false;
    }
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        int temp = nums[j];
        j = (j + temp) % nums.size();
        if(hash2[j] == 1)
            return false;
        hash2[j] = 1;
    }
    if(j != 0)
        return false;
    for(int i = 0; i < nums.size(); i++) {
        if(hash2[i] == 0) {
            return false;
        }        
    }
    return true;
}

int main() {
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    fin >> n;
    fin.close();
    n++;
    init(n);
    while(!solve()) {
        n++;
        hash1.assign(hash1.size(), 0);
        hash2.assign(hash2.size(), 0);
        init(n);
    }
    fout << n << endl;
    fout.close();

    return 0;
}
