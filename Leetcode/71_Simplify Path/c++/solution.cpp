/*******************
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. 
For more information, see: Absolute path vs relative path in Linux/Unix
Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. 
The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
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
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) ++i;
            if(i == path.size()) break;
            int sta = i;
            while(path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string cur = path.substr(sta,end - sta + 1);
            if(cur == ".."){
                if(!v.empty()) v.pop_back();
            }
            else if(cur != ".")
                v.push_back(cur);
        }
        if (v.empty()) return "/";
        string res;
        for(int i = 0; i < v.size(); ++i){
            res +='/'+ v[i];
        }
        return res;
    }
};

int main() {
    return 0;
}