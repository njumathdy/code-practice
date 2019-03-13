/*******************
*******************/
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n;
int d;
int res = 0;
int a[2000001], b[2000001];
map<int, int> mapBank;

void rob(int* a, int* b) {
    int max[n];

    // 找出位置i之后的金额最大的银行
    max[n-1] = b[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(max[i+1] < b[i])
            max[i] = b[i];
        else 
            max[i] = max[i+1];
    }

    // 找出第i个银行可以选择的第二个银行的范围
    int index[n];
    for(int i = 0; i < n; i++) {
        int j = 1;
        if(i != 0) 
            j = index[i-1]; // 能够选择的范围一定比前一个要小，所以从index[i-1]开始查找。
        for(; j < n; j++) {
            if(a[j] - a[i] >= d) {
                index[i] = j; // 找到的第一个满足条件的银行即指明了范围，跳出本次循环
                break;
            }
        }
        if(j == n) { // j等于n，说明没有满足条件的银行
            index[i] = -1;
            for(; i < n; i++) 
                index[i] = -1;
            break; // 后面的i也无需遍历  
        }       
    }

    // 求最大值
    for(int i = 0; i < n - 1; i++) {
        if(index[i] == -1)
            break;

        int temp = max[index[i]] + b[i];
        res = temp > res ? temp : res;
    }
    
    return;
}

int main() {
    cin >> n;
    cin >> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        mapBank[a[i]] = b[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++) 
        b[i] = mapBank[a[i]];

    rob(a, b);
    cout << res << endl;

    return 0;
}