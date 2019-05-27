/*******************
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
The valid operators are +, - and *.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

// recursive
class Solution1 {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // divide and conquer
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

// with memorization
class Solution2 {
public:
    vector<int> diffWaysToCompute(string input) {
        map<string, vector<int> > cache;
        return diffWaysToCompute(input, 0, input.size()-1, cache);
    }
private:
    vector<int> diffWaysToCompute(string& input, int start, int end, map<string, vector<int> >& cache) {
        string key=to_string(start)+to_string(end);
        if(cache.count(key)) return cache[key];
        vector<int> result;
        int num=0;
	    for(int i=start; i<=end; ++i) {
	        if(input[i]!='+' && input[i]!='-' && input[i]!='*')
	            num=num*10+(input[i]-'0');
		    else{ 
    		    vector<int> left=diffWaysToCompute(input, start, i-1, cache);
    		    vector<int> right=diffWaysToCompute(input, i+1, end, cache);
    		    for(auto l:left){
    		        for(auto r: right){
    		            if(input[i]=='+')
    		                result.push_back(l+r);
    		            else if(input[i]=='-')
    		                result.push_back(l-r);
    		            else if(input[i]=='*')
    		                result.push_back(l*r);
    		        }
    		    }
		    }    
        }
        if(result.size()==0) result.push_back(num); //only single number
        return cache[key]=result;
    }
};

int main() {
    return 0;
}