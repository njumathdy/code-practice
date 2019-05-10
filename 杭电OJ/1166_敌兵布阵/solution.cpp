#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#define mem(a,b) memset(a,b,sizeof(a))
#define _mem(a,b) memset(a,0,(b+1)<<2)

using namespace std;

typedef long long ll;
const int maxn =  5*1e4+5;
const int INF = 0x3f3f3f3f;
int c[maxn];
inline int lowbit(int x) {
    return (x & -x);
}
void update(int x,int y,int n){
    for(int i=x;i<=n;i+=lowbit(i))
        c[i] += y;
}
int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    int t;
    int n;
    int x,y,z;
    string s;
    cin >> t ;
    for(int j=1;j<=t;j++){
        scanf("%d",&n);
        _mem(c,n);      //初始化数组中前n+1个数为0
        for(int i=1;i<=n;i++){
            scanf("%d",&z);
            update(i,z,n);
        }
        cout <<"Case "<<j<<":"<<endl;
        while(1){
            cin >> s;
            if(s[0] == 'E')
                break;
            scanf("%d%d",&x,&y);
            if(s[0] == 'Q')
                cout << getsum(y)-getsum(x-1)<<endl;
            else if(s[0] == 'A')
                update(x,y,n);
            else
                update(x,-y,n);
        }
    }

    return 0;
}