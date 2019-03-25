#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

bool isIn(string s, char c) {
    if(s == "") return -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) return 1;
    }
    return 0;
}
int lengthOfLongestSubstring(string s) {
    int length = 1;
    int l = s.size();
    if(l == 1) return 1;
    for(int i = 0; i < l; i++) {
        cout << i << endl;
        int j;
        for(j = 1; j < l-i; j++) {
            cout << j << endl;
            if(isIn(s.substr(i, j), s[i+j])) break;
        }
        length = max(length, j);
        cout << length << endl;
        cout << "this round ends" << endl;
    }
    return length;
}

int main() {
    string s = "pwwkew";
    int l = lengthOfLongestSubstring(s);

    return 0;
}
