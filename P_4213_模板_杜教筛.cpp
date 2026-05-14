#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define int long long

const ll N = 2e6+10;
ll prime[N+10],mu[N+10],muSum[N+10],phi[N+10],pcnt;
ll phiSum[N+10];
bool vis[N+10];
map<ll,ll> muMp;

void Sieve(int n){
    mu[1] = 1;
    phi[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            mu[i] = -1;
            phi[i] = i-1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            int x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                mu[x] = 0;
                phi[x] = p*phi[i];
                break;
            }else{
                mu[x] = -mu[i];
                phi[x] = (p-1)*phi[i];
            }
        }
    }
}

void Init(int n){
    Sieve(n);
    for(int i=1;i<=n;++i){
        muSum[i] = muSum[i-1]+mu[i];
        phiSum[i] = phiSum[i-1]+phi[i];
    }
}

ll MuSum(ll n){
    if(n>=N){
        if(muMp[n])return muMp[n];
        ll ans = 1;
        for(int l=2,r;l<=n;l=r+1){
            int dn = n/l;
            r = n/dn;
            ans -= 1LL*(r-l+1)*MuSum(dn);
        }
        return muMp[n]=ans;
    }
    return muSum[n];
}

ll PhiSum(ll n){
    if(n>=N){
        ll ans = 0;
        for(int l=1,r;l<=n;l=r+1){
            int dn = n/l;
            r = n/dn;
            ans += (MuSum(r)-MuSum(l-1))*dn*dn;
        }
        return (ans+1)/2;
    }
    return phiSum[n];
}

inline void solve(){
    ll n;cin>>n;
    ll m = MuSum(n);
    cout<<PhiSum(n)<<" "<<m<<"\n";
    return;
}

signed main(){
    Init(N);
    ll t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}