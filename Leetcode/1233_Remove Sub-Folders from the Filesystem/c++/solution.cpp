/*******************
Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.
If a folder[i] is located within another folder[j], it is called a sub-folder of it.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. 
For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.
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
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        int pre = 0;
        for(int i=1;i<folder.size();i++){
            if(folder[i].size() > folder[pre].size()){
                int flag = memcmp(folder[pre].c_str(), folder[i].c_str(), folder[pre].size());
                if(flag == 0 && folder[i][folder[pre].size()] == '/'){
                    continue;
                }
            }
            ans.push_back(folder[i]);
            pre = i;
        }
        return ans;
    }
};

int main() {
    return 0;
}