/**********************
Shil has a very hard time waking up in the morning each day, so he decides to buy a powerful alarm clock to Kickstart his day. 
This Alarm is called a Kickstart Alarm. It comes pre-configured with K powerful wakeup calls. 
Before going to bed, the user programs the clock with a Parameter Array consisting of the values A1, A2, ..., AN. 
In the morning, the clock will ring K times, with the i-th wakeup call having power POWERi.

To calculate POWERi, the alarm generates all the contiguous subarrays of the Parameter Array and calculates the summation of the i-th exponential-power of all contiguous subarrays. 
The i-th exponential-power of subarray Aj, Aj+1, ..., Ak is defined as Aj × 1i + Aj+1 × 2i + Aj+2 × 3i + ... + Ak × (k-j+1)i. 
So POWERi is just the summation of the i-th exponential-power of all the contiguous subarrays of the Parameter Array.

Tonight, Shil is using his Kickstart Alarm for the first time. 
Therefore, he is quite worried about the sound the alarm might make in the morning. 
It may wake up the neighbors, or, worse yet, it may wake up the whole planet! However, calculating the power of each wakeup call is quite difficult for him. 
Given K and the Parameter Array A1, A2, ..., AN, can you help him by calculating the summation of power of each wakeup call: POWER1 + POWER2 + ... + POWERK?
**********************/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 用1000000007是因为保证在计算过程中不会溢出
const ll MOD = pow(10,9)+7;

// fast power: 已经保证不会算术溢出
ll getPow(ll a,ll p){
  ll ret = 1,cp = a;
  while(p){
    if(p&1) ret = (ret*cp)%MOD;
    p >>= 1;
    cp = (cp*cp)%MOD;
  }
  return ret;
}

// 计算长度为i的数组对应的级数和
ll getK(ll i,ll k){
  if(i == 1) return k%MOD;
  // Multipyting by inverse modulo of x-1. 利用到1000000007是质数。
  ll ret = ((i*(getPow(i,k)-1)%MOD)*getPow(i-1,MOD-2))%MOD;
  return ret;
}

int main(){
  int T;
  cin >> T;
  for(int k = 1; k <= T; ++k){
    ll N,K,x1,y1,C,D,E1,E2,F;
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;
    vector<ll> A(N);
    // 计算数组A的各元素
    A[0] = (x1+y1)%F;
    ll CD = C+D,E = E1+E2;
    for(ll i = 1; i < N; ++i) A[i] = (CD*A[i-1]+E)%F;

    // kval: 连续子数组长度, nb: A[i]出现的次数
    ll psum = 0,nb = 1,kval = N,ret = 0;
    for(ll i = N-1; i >= 0; --i){
      psum = (psum+nb*A[i])%MOD;
      ++nb;
      ret = (ret+psum*getK(kval,K))%MOD;
      --kval;
    }
    cout << "Case #" << k << ": " << ret << "\n";
  }
  return 0;
}