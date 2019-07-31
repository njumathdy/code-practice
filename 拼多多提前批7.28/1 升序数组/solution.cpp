#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> A, B;

int main() {
    string a, b;

    getline(cin, a);
    getline(cin, b);

    // 这里有问题，没有考虑到整数大于10的情况
    for(int i = 0; i < a.size(); i+=2) {
        A.push_back(a[i]-'0');
    }
    for(int i = 0; i < b.size(); i+=2) {
        B.push_back(b[i]-'0');
    }

    int low1, low2, high1, high2, ind;
    for(int i = 0; i < A.size(); i++) {
        if(i > 0 && A[i] <= A[i-1]) {
            low1 = A[i-1];
            if(i < A.size() - 1)
                high1 = A[i+1];
            else
                high1 = INT_MAX;    
            ind = i;
            high2 = A[i];
            if(i == 1) {
                low2 = INT_MIN;
            } else {
                low2 = A[i-2];
            }
            break;
        }
    }
    int res = 0;
    bool existence1 = false, existence2 = false;
    for(auto num : B) {
        if(num > low1 && num < high1) {
            res = max(res, num);
            existence1 = true;
        }
    }
    for(auto num : B) {
        if(num > low2 && num < high2) {
            res = max(res, num);
            existence2 = true;
        }
    }
    if(existence1 || existence2) {
        if(existence1) {
            A[ind] = res;
            for(auto num : A) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            A[ind-1] = res;
            for(auto num : A) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}