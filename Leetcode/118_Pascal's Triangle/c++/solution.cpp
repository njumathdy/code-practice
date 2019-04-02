/*******************
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if(numRows < 1)
            return ans;
        ans.push_back(vector<int>(1, 1));
        if(numRows == 1)
            return ans;
        ans.push_back(vector<int>(2, 1));
        if(numRows == 2)
            return ans;
        
        for(int i = 2; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 0; j < i-1; j++) {
                int t = ans[i-1][j] + ans[i-1][j+1];
                temp.push_back(t);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}