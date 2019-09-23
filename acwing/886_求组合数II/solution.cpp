#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,mod=1e9+7;

int fact[N],infact[N];

int qsm(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}

int main(){
    fact[0]=1,infact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        infact[i]=(ll)infact[i-1]*qsm(i,mod-2,mod)%mod;
    }

    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;

        cout<<(ll)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}