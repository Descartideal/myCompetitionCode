#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using ld = long double;

signed main(){
    ll n,m;cin>>n>>m;
    if(n>m)swap(n,m);
    
    ld phi = (1.0L+sqrtl(5.0L))/2.0L;
    ll k = m-n;
    ll t = (ll)floor(k*phi);

    cout<<(t==n?0:1)<<"\n";
    return 0;
}