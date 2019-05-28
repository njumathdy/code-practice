/*******************
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. 
You could assume there always exists an answer.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if(list1.empty() || list2.empty())
            return {};
        
        unordered_map<string, int> table;
        for(int i = 0; i < list1.size(); i++) {
            table[list1[i]] = i;
        }
        int res = list1.size() + list2.size();
        vector<string> ans;
        for(int i = 0; i < list2.size(); i++) {
            if(table.find(list2[i]) != table.end()) {
                if(ans.empty()) {
                    ans.push_back(list2[i]);
                    res = i + table[list2[i]];
                }    
                else if(i+table[list2[i]] < res) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    res = i + table[list2[i]];
                } else if(i+table[list2[i]] == res) {
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};

int main() {
    return 0;
}