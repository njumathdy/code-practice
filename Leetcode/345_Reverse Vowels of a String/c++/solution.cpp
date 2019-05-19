/*******************
Write a function that takes a string as input and reverse only the vowels of a string.
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
    string reverseVowels(string s) {
        if(s.size() < 2)
            return s;
        
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            while(i < n && vowel.find(s[i]) == vowel.end())
                i++;
            while(j >= 0 && vowel.find(s[j]) == vowel.end())
                j--;
            
            if(i >= j)
                return s;
            else 
                swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};

int main() {
    return 0;
}