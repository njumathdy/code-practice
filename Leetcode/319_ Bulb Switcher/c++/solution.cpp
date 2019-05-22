/*******************
There are n bulbs that are initially off. 
You first turn on all the bulbs. 
Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution1 {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(isSquare(i))
                res++;
        }
        
        return res;
    }
    
    bool isSquare(int n) {
        int a = (int)(sqrt(n) + 0.5);
        return a * a == n;
    }
};

class Solution2 {
public:
    int bulbSwitch(int n) {
        int counts = 0;
    
        for (int i=1; i*i<=n; ++i) {
            ++ counts;    
        }
    
        return counts;
    }  
};

int main() {
    return 0;
}