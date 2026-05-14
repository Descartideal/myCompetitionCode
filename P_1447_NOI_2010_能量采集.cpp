#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int N = 1e5+10;

int pcnt;
int prime[N+10],phi[N+10],Sphi[N+10];
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
            int x = p*i;
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
    int n,m;cin>>n>>m;
    if(n>m)swap(n,m);
    int limit = n;
    Sieve(n);
    for(int i=1;i<=n;++i){
        Sphi[i] = Sphi[i-1]+phi[i];
    }

    ll res = 0;
    for(int l=1,r;l<=limit;l=r+1){
        int dn=n/l;
        int dm=m/l;
        r = min(n/dn,m/dm);

        res += (Sphi[r]-Sphi[l-1])*dn*dm;
    }
    res *= 2;
    res -= n*m;

    cout<<res<<"\n";
}