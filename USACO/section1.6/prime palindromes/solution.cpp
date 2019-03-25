/*
ID: mg172101
LANG: C++11
PROG: pprime
*/

/************************
 * 本题直接暴力解法不难，不过由于时间限制为1s，所以要改变思路。
 * 数据范围是5-100，000，000，找出所有素数时间不允许。方法是先用遍历找出所有palindromes，然后在palindromes中
 * 找出所有素数。
 ***********************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> pal(50000, 0);
int total = 0;

bool isPrime(int n) {
    if(n == 1) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}
void createPal() {
    for(int i = 1; i < 10; i++) {
        pal[total] = i;
        total++;
    }
    pal[total] = 11;
    total++;
    for(int a = 1; a < 10; a+=2) {
        for(int b = 0; b < 10; b++) {
            pal[total] = a*100 + b*10 + a;
            total++;
        }
    }
    for(int a = 1; a < 10; a+=2) {
        for(int b = 0; b < 10; b++) {
            for(int c = 0; c < 10; c++) {
                pal[total] = a*10000 + b*1000 + c*100 + b*10 + a;
                total++;
            }
        }
    }
    for(int a = 1; a < 10; a+=2) {
        for(int b = 0; b < 10; b++) {
            for(int c = 0; c < 10; c++) {
                for(int d = 0; d < 10; d++) {
                    pal[total] = a*1000000 + b*100000 + c*10000 + d*1000 + c*100 + b*10 + a;
                    total++;
                }
            }
        }
    }
}

int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a, b;
    fin >> a >> b;
    createPal();
    sort(pal.begin(), pal.begin()+total);
    for(int i = 0; i < total; i++) {
        if(pal[i] >= a && pal[i] <= b && isPrime(pal[i])) fout << pal[i] << endl; 
    }
    fin.close();
    fout.close();
    

    return 0;
}
