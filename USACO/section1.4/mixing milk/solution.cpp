/*
ID: mg172101
LANG: C++11
PROG: milk
*/

/*
本题是很简单的一个贪心算法，数学原理为排序不等式。实现起来的关键就是排序的实现，我一开始的思路是将价格和数量作为一个键值对
储存到map中，不过这没有考虑到价格可以重复的问题，导致出错。所以需要自己实现一个排序算法，对价格排序，同时对数量也要进行操
作，使得排序后两者仍相互对应。
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int price[5100], amount[5100];

void sortTwoArrays(int l, int r) {
    long i,j,x,y;
	i=l;j=r;x=price[(i+j)/2];
	do
	{
		while (price[i]<x) ++i;
		while (price[j]>x) --j;
		if (i<=j)
		{
			y=price[i];price[i]=price[j];price[j]=y;
			y=amount[i];amount[i]=amount[j];amount[j]=y;
			i++;j--;
		}
	}
	while(i<=j);
	if (i<r) sortTwoArrays(i,r);
	if (l<j) sortTwoArrays(l,j);
}

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int N, n;
    long p, a, sum = 0;
    
    fin >> N >> n;
    // cout << N << " " << n << endl;

    // map<int, int> price;
    // for(int i = 0; i < n; i++) {
    //     fin >> price[i] >> amount[i];
    // }
    // sort(price1, price1+n);//将价格从小到大排序
    // for(int i = 0; i < n; i++) {
    //     cout << price1[i] << endl;
    // }
    sortTwoArrays(0, n-1);
    int i = 0;
    while(N > 0) {
        if(N > amount[i]) {
            sum += price[i] * amount[i];
            // cout << sum << endl;
            N = N - amount[i];
            i++;
            // cout << i << endl;
        } else {
            sum += N * price[i];
            // cout << price[i] << endl;
            // cout << sum << endl;
            N = 0;
        }
    }
    fout << sum << endl;



    return 0;
}
