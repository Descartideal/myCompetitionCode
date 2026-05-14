#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 1e6+20;

int pcnt;
int prime[N+10],Mu[N+10],MuSumf[N+10];
bool vis[N+10];

void Sieve(int n){
    Mu[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            Mu[i] = -1;
            prime[++pcnt] = i;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                Mu[x] = 0;
                break;
            }else{
                Mu[x] = -Mu[i];
            }
        }
    }
}

signed main(){
    int n,m,d;cin>>n>>m>>d;n/=d,m/=d;
    if(n>m)swap(n,m);
    int limit = n;
    Sieve(limit);
    for(int i=1;i<=limit;++i){
        MuSumf[i] = MuSumf[i-1]+Mu[i];
    }

    

    ll res = 0;
    for(int l=1,r;l<=limit;l=r+1){
        int dn = n/l;
        int dm = m/l;
        r = min(n/dn,m/dm);
        res += (MuSumf[r]-MuSumf[l-1])*dn*dm;
    }

    cout<<res<<"\n";
}