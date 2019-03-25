/*
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int x[2][2] = {-1};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << x[i][j] << endl;
        }
    }
    return 0;
}
