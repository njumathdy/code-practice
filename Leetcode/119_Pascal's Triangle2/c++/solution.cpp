/*******************
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 动态规划，注意从后往前。
class Solution1 {
public: 
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;  
    }
};

// 数学方法：可以直接求出公式。
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        if(rowIndex == 1)
            return {1,1};
        
        vector<int> ans(rowIndex+1, 0);
        for(int i = 0; i <= rowIndex; i++)
            ans[i] = combinator(rowIndex, i);
        return ans;
    }
    
    int combinator(int n, int m) {
        if(m == 0)
            return 1;
        if(m > n / 2)
            return combinator(n, n-m);
        long long a = 1;
        for(int i = 1; i <= m; i++) {
            a *= (n-m+i);
            a /= i;
        }
        return a;
    }
};

int main() {
    return 0;
}