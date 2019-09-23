/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

const int maxn = 1000000;

int n;
string n1, n2;
int res;
unordered_set<string> prime = {"000002", "000003"};

bool isPrime(int num) {
    if(num == 1) return false;
    if(num < 4) return true;

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

string trans(int num) {
    int temp = num;
    int count = 0;
    while(temp) {
        count++;
        temp /= 10;
    }
    if(count == 6) return to_string(num);
    string s = "";
    for(int i = 1; i <= 6-count; i++) s += '0';
    s += to_string(num);
    return s;
}

void generatePrime() {
    for(int i = 5; i < maxn; i+=2) {
        if(isPrime(i)) {
            prime.insert(trans(i));
        }
    }
}

bool dis(string s1, string s2) {
    int dis = 0;
    for(int i = 0; i < 6; i++) {
        if(s1[i] != s2[i]) dis++;
        if(dis > 1) return false;
    }

    return true;
}

void solve() {
    if(n1 == n2) {
        cout << 0 << endl;
        return;
    }
    queue<string> q;
    unordered_set<string> s;
    q.push(n1);
    s.insert(n1);
    while(!q.empty()) {
        res++;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            string temp = q.front();
            q.pop();
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k <= 9; k++) {
                    if(temp[j] == '0' + k) continue;
                    char c = temp[j];
                    temp[j] = '0' + k;
                    if(prime.find(temp) == prime.end() || s.find(temp) != s.end()) {
                        temp[j] = c;
                        continue;
                    } 
                    if(temp == n2) {
                        printf("%d\n", res);
                        return;
                    } else {
                        q.push(temp);
                        s.insert(temp);
                    }
                    temp[j] = c;
                }
            }   
        }
    }
    cout << -1 << endl;
}

int main() {
    generatePrime();
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> n1 >> n2;
        res = 0;
        solve();
    }
    
    return 0;
}