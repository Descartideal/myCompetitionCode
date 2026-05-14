#include <bits/stdc++.h>
using namespace std;
//#define int long long
using ll = long long;

const int N = 5e4+10;

int mu[N+10],muSumf[N+10],tauv[N+10],prime[N+10],pcnt;
bool vis[N+10];
ll tauvSumf[N+10];

void Sieve(int n){
    mu[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            mu[i] = -1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                mu[x] = 0;
                break;
            }else{
                mu[x] = -mu[i];
            }
        }
    }
}

void Init(int n){
    Sieve(n);
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j+=i){
            tauv[j]++;
        }
    }

    for(int i=1;i<=n;++i){
        muSumf[i] = muSumf[i-1]+mu[i];
        tauvSumf[i] = tauvSumf[i-1]+tauv[i];
    }
}

inline void solve(){
    int n,m;cin>>n>>m;
    if(n>m)swap(n,m);
    
    ll ans = 0;
    for(int l=1,r;l<=n;l=r+1){
        int dn = n/l;
        int dm = m/l;
        r = min(n/dn,m/dm);
        ans += 1LL*(muSumf[r]-muSumf[l-1])*tauvSumf[dn]*tauvSumf[dm];
    }
    cout<<ans<<"\n";
    return;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    Init(N);

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}