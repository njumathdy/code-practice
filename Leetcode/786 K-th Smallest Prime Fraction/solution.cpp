/*******************
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

class node {
public:
    int p;
    int q;
    double val;
    node(int m,int n,double value):p(m), q(n), val(value) {} 
};
    
bool operator >(node a1, node a2) {
    return a1.val > a2.val;
}

// based on heap
class Solution1 {
public:    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> res;
        priority_queue<node,vector<node>,greater<node> > pq;
        for (int i=1;i<A.size();++i) {
            double cc = double(A[0])/double(A[i]);
            node a(0,i,cc);
            pq.push(a);
        }
        int cnt=0;
        int fenzi,fenmu;
        while (cnt < K) {
            fenzi = pq.top().p;
            fenmu = pq.top().q;
            pq.pop();
            double cc = double(A[fenzi+1])/double(A[fenmu]);
            node a(fenzi+1,fenmu,cc);
            pq.push(a);
            cnt += 1;
        }
        res.push_back(A[fenzi]);
        res.push_back(A[fenmu]);
        return res;
    }
};

// based on binary search
class Solution2 {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        int p, q;
        double max_f;
        
        double l = 0, r = 1;
        while (l < r) {
            double m = (l + r) * 0.5;
            int total = 0;
            max_f = 0;
            for (int i = 0, j = 1; i < n - 1; ++i) {
                while (j < n && A[i] > A[j] * m) j++;
                if (j == n) 
                    break;
                total += n - j;
                double f = static_cast<double>(A[i]) / A[j];
                if (f > max_f) {
                    max_f = f;
                    p = i;
                    q = j;
                }
            }
            if (total == K) return {A[p], A[q]};
            if (total > K) r = m;
            else l = m;
        }
        return {};
    }
};

int main() {
    return 0;
}