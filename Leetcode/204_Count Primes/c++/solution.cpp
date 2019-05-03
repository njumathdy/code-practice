/*******************
Count the number of prime numbers less than a non-negative number, n.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution1 {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        int res = 1;
        for(int i = 3; i < n; i += 2) {
            if(isPrime(i))
                res++;
        }
        
        return res;
    }
    
    bool isPrime(int n) {
        if(n == 2)
            return true;
        
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0)
                return false;
        }
        
        return true;
    }
};

class Solution2 {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true); 
        for(int i = 2; i*i < n;i++)
        {
            if(prime[i] == true)
            {
                for(int j = i*i ; j< n;j+=i)
                    prime[j] = false;
            }
        }
        int count = 0;
        for(int i = 2;i < n;i++)
            if(prime[i] == true)
                count++;
        return count;
    }
};

int main() {
    return 0;
}