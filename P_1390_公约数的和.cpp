#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 2e6+10;

int pcnt;
int prime[N+10],phi[N+10];
ll phiSumf[N+10];
int vis[N+10];

void Sieve(int n){
    phi[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            phi[i] = i-1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                phi[x] = p*phi[i];
                break;
            }else{
                phi[x] = (p-1)*phi[i];
            }
        }

    }
}

signed main(){
    int n;cin>>n;
    Sieve(n);
    for(int i=1;i<=n;++i){
        phiSumf[i] = phiSumf[i-1]+phi[i];
    }

    ll ans = 0;
    for(int l=1,r;l<=n;l=r+1){
        int dn = n/l;
        r = n/dn;
        ans += (phiSumf[r]-phiSumf[l-1])*dn*dn;
    }

    ans -= n*(n+1)/2;
    ans /= 2;

    cout<<ans<<"\n";
}