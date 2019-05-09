/*******************
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
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

// union-find
class Solution {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        unordered_map<string, int> varID; // map var name to its ID 
        vector<int> par;                  // par[v2]==v1 ;  v1 is v2's parent
        vector<double> parEq;             // parEq[v2]==t ; v1 is t times of v2 

        for (int i=0; i<equations.size(); i++) // process equations
        {
            string& v1Name = equations[i][0];
            string& v2Name = equations[i][1];
            double x = values[i]; // v1 is x times of v2
            int v1, v2;
            if (varID.count(v1Name)==0){ //new variable
                v1 = par.size();
                par.push_back(v1); //par[v1]==v1, v1 is itself's parent
                parEq.push_back(1); 
                varID[v1Name] = v1;
            }
            else  
                v1 = varID[v1Name];
            
            if (varID.count(v2Name)==0) {
                v2 = par.size();
                par.push_back(v2);  
                parEq.push_back(1);
                varID[v2Name] = v2; 
            }
            else  v2 = varID[v2Name];
            
            int r1, r2;
            double t1, t2;
            r1 = findRoot(par, parEq, v1, t1); //r1 is t1 times of v1
            r2 = findRoot(par, parEq, v2, t2); //r2 is t2 times of v2
            par[r2] = r1;
            parEq[r2] = t1 * x / t2;           //do simple math here
        }

        vector<double> res;
        for (auto& q : queries) // process queries
        {
            int v1, v2;
            if (varID.count(q[0])==1 && varID.count(q[1])==1 ) {
                v1 = varID[q[0]];
                v2 = varID[q[1]];
            }
            else {
                res.push_back(-1);
                continue;
            }
            int r1, r2;
            double t1, t2;
            r1 = findRoot(par, parEq, v1, t1); //r1 is t1 times of v1
            r2 = findRoot(par, parEq, v2, t2); //r2 is t2 times of v2
            if (r1 != r2) res.push_back(-1);
            else res.push_back(t2/t1);
        }
        return res;
    }
    
    int findRoot(vector<int>& par, vector<double>& parEq, int v, double& t) {
        t = 1;
        while (v != par[v]) {
            // path compression
            parEq[v] = parEq[v] * parEq[par[v]];
            par[v] = par[par[v]];
            // climb up
            t *= parEq[v];
            v = par[v];
        }
        return v;
    }
};

int main() {
    return 0;
}