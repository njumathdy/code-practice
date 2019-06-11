/*******************
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)
            return false;
        
        if(z == x || z == y || z == x + y)
            return true;
        
        return z % gcd(x, y) == 0;
    }
    
    int gcd(int x, int y) {
        while(y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        
        return x;
    }
};

int main() {
    return 0;
}