/*******************
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        for(auto c : J)
            set.insert(c);
        
        int res = 0;
        for(auto c : S) {
            if(set.find(c) != set.end())
                res++;
        }
        
        return res;
    }
};

int main() {
    return 0;
}