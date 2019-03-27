/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <iostream>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Position {
    int x;
    int y;
};

vector<Position> point(6);

double distance(Position p1, Position p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y-p2.y));
}

double ans = double(INT_MAX);

int main() {
    point[0].x = 0;
    point[0].y = 0;
    for(int i = 1; i <= 5; i++)
        cin >> point[i].x >> point[i].y;

    for(int i = 1; i <= 5; i++) {
        // double res = 0.0;
        // res += distance(point[0], point[i]);
        for(int j = 1; j <= 5; j++) {
            if(j != i) {
                // res += distance(point[i], point[j]);
                for(int k = 1; k <= 5; k++) {
                    if(k != i && k != j) {
                        // res += distance(point[j], point[k]);
                        for(int m = 1; m <= 5; m++) {
                            if(m != k && m != j && m != i) {
                                // res += distance(point[k], point[m]);
                                for(int n = 1; n <= 5; n++) {
                                    if(n != m && n != k && n != j && n != i) {
                                        double res = 0.0;
                                        res += distance(point[0], point[i]);
                                        res += distance(point[i], point[j]);
                                        res += distance(point[j], point[k]);
                                        res += distance(point[k], point[m]);
                                        res += distance(point[m], point[n]);
                                        res += distance(point[n], point[0]);

                                        ans = min(ans, res);
                                    }   
                                }
                            }   
                        }
                    }
                }
            }
        }
    }
    
    cout << (int)ans << endl;
    
        
    return 0;
}