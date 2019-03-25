/*
ID: mg172101
LANG: C++11
PROG: sprime
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> v1 = {2, 3, 5, 7};
vector<int> v2 = {1, 3, 7, 9};
// vector<int> sprime;


bool isPrime(int n) {
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}
vector<int> superprime(int n) {
    if(n == 1) return v1;
    vector<int> res = superprime(n-1);
    vector<int> sprime;
    for(int i : res) {
        for(int j : v2) {
            if(isPrime(i*10+j)) sprime.push_back(i*10+j);
        }
    } 
    return sprime;  
}
int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    fin >> N;
    fin.close();
    vector<int> res = superprime(N);
    for(int i : res) {
        fout << i << endl;
    }
    fout.close();
    
    return 0;
}
