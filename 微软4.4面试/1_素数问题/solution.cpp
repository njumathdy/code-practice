/*******************
 * 给定一个正整数n，求出小于n的所有素数，并求出每个素数的排列中有多少个素数。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int n;
vector<int> prime;
map<string, vector<int> > t;

string integer2String(int integer) {
    string s = "";
    vector<int> digits;
    int temp;
    while(integer) {
        temp = integer % 10;
        digits.push_back(temp);
        integer /= 10;
    }
    sort(digits.begin(), digits.end());
    for(int i = 0; i < digits.size(); i++) {
        s += ('0' + digits[i]);
    }
    return s;
}

bool isPrime(int m) {
    if(m == 1 || m == 2)
        return true;

    for(int i = 2; i <= sqrt(m); i++) {
        if(m % i == 0)
            return false;
    }
    return true;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(isPrime(i))
            prime.push_back(i);
    }
    for(int i = 0; i < prime.size(); i++) {
        string s = integer2String(prime[i]);
        if(t.find(s) != t.end())
            t[s].push_back(prime[i]);
        else {
            t[s] = { prime[i] };
        }
    }
    for(auto iter = t.begin(); iter != t.end(); iter++) {
        cout << iter -> first << ": " ;
        for(int i = 0; i < iter->second.size(); i++)
            cout << iter->second[i] << " ";
        cout << endl;
    }
    return 0;
}