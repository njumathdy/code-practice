/*******************
 * 给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
*******************/
#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int n, num;
    long long max_mul;
    long long max1, max2, max3, min1, min2;
    max1 = max2 = max3 = INT_MIN;
    min1 = min2 = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if(num < min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if(num < min2)
        {
            min2 = num;
        }
         
        if(num > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if(num > max2)
        {
            max3 = max2;
            max2 = num;
        }
        else if(num > max3)
        {
            max3 = num;
        }
    }
    max_mul = max1*max2*max3 > max1*min1*min2 ? max1*max2*max3 : max1*min1*min2;
    cout << max_mul << endl;
    
    return 0;
}