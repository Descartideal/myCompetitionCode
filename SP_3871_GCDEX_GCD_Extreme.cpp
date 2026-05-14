#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+20;
//#define int long long

ll phiSum[N+10];
int pcnt,prime[N+10],phi[N+10];
bool vis[N+10];

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
    Sieve(N);
    for(int i=1;i<=N;++i){
        phiSum[i] = phiSum[i-1]+phi[i];
    }

    ll n;cin>>n;
    while(n!=0){
        ll ans = 0;
        for(int l=1,r;l<=n;l=r+1){
            int dn = n/l;
            r = n/dn;
            ans += 1LL*(phiSum[r]-phiSum[l-1])*dn*dn;
        }
        ans -= n*(n+1)/2;
        ans /= 2;
        cout<<ans<<"\n";
        cin>>n;
    }
}