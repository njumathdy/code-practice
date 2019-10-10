/*******************
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
private: 
    void dfs(vector<vector<int> >& A, int i, int j,queue<pair<int,int> >& qt) {
	    if (i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j] != 1)
		    return;
	    qt.push({ i,j });
	    A[i][j] = 2;
	    dfs(A, i + 1, j,qt);
	    dfs(A, i - 1, j, qt);
	    dfs(A, i, j + 1, qt);
	    dfs(A, i, j - 1, qt);
}
public:
    int shortestBridge(vector<vector<int> >& A) {
	    queue<pair<int,int> > qt;
	    int minval = INT_MAX;
	    bool found = false;
	    for (int i = 0; i < A.size(); i++) {
		    for (int j = 0; j < A[i].size(); j++) {
			    if (A[i][j] == 1) {
				    dfs(A, i, j,qt);
				    found = true;
				    break;
			    }
		    }
		    if (found)
			    break;
	    }
	    int initial = 0;
	    while (!qt.empty()) {
		    initial++;
		    int size = qt.size();
		    for (int i = 0; i < size; i++) {
			    int r = qt.front().first;
			    int c = qt.front().second;
			    qt.pop();
			    if (r + 1 < A.size()) {
				    if (A[r + 1][c] == 0) {
					    A[r + 1][c] = initial + 1;
					    qt.push({ r + 1,c });
				    }
				    else if (A[r + 1][c] == 1) {
					    minval = min(initial, minval);
				    }
			    }
			    if (c + 1 < A[r].size()) {
				    if (A[r][c+1] == 0) {
					    A[r][c+1] = initial + 1;
					    qt.push({ r,c+1 });
				    }
				    else if (A[r][c+1] == 1) {
					    minval = min(initial,minval);
				    }
			    }
			    if (r - 1 >= 0) {
				    if (A[r - 1][c] == 0) {
					    A[r - 1][c] = initial + 1;
					    qt.push({ r - 1,c });
				    }
				    else if (A[r - 1][c] == 1) {
					    minval = min(initial, minval);
				    }
			    }
			    if (c - 1 >= 0) {
				    if (A[r][c - 1] == 0) {
					    A[r][c - 1] = initial + 1;
					    qt.push({ r,c - 1 });
				    }
				    else if (A[r][c - 1] == 1) {
					    minval = min(initial, minval);
				    }
			    }
		    }
	    }
	    return minval-1;
    }
};

int main() {
    return 0;
}