/*******************
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.
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
    int countSegments(string s) {
        if(s.empty())
            return 0;
        
        int n = s.size();
        int i = 0, j = n-1;
        while(i < n && s[i] == ' ')
            i++;
        while(j > 0 && s[j] == ' ')
            j--;
        if(i == n)
            return 0;
        int count = 1;
        while(i < j) {
            while(i < j && s[i] != ' ') {
                i++;
            }
            if(i == j)
                return count;
            else {
                count++;
                while(i < j && s[i] == ' ')
                    i++;
            }   
        }
        
        return count;
    }
};

int main() {
    return 0;
}