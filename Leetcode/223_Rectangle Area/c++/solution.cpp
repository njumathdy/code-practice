/*******************
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        if(C <= E || G <= A || D <= F || H <= B)
            return area1 + area2;
        
        int dx = min(C, G) - max(A, E);
        int dy = min(D, H) - max(B, F);
        
        return (long long)area1 + area2 - dx * dy;
    }
};

int main() {
    return 0;
}