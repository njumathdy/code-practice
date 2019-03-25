/*******************
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int a = 2421;
    cout << a / 1000 << endl;
    string s = "";
    cout << s + 'a' << endl;
    map<char, int> mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    cout << mapping['I'] << endl;

    return 0;
}
