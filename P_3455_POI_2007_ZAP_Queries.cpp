#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

const int N = 50005;

int pcnt;
int prime[N],Mu[N],MuSumf[N];
bool vis[N];


void linearSieveMu(int n){
    Mu[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            Mu[i] = -1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            if(i*p>n)break;
            vis[i*p] = true;
            if(i%p==0){
                Mu[i*p] = 0;
                break;
            }else{
                Mu[i*p] = -Mu[i];
            }
        }
    }
}

void Init(int n){
    linearSieveMu(n);
    for(int i=1;i<=n;++i){
        MuSumf[i] = MuSumf[i-1]+Mu[i];
    }
}

ll f(int n,int m){
    if(n>m)swap(n,m);
    ll ans = 0;

    int limit = n;
    for(int l=1,r;l<=limit;l=r+1){
        int dn = n/l;
        int dm = m/l;
        r = min(n/dn,m/dm);
        ans += (MuSumf[r]-MuSumf[l-1])*dn*dm;
    }

    return ans;
}

ll g(int n,int m,int k){
    if(n>m)swap(n,m);
    return f(n/k,m/k);
}

void solve(){
    int a,b,k;cin>>a>>b>>k;
    ll res = g(a,b,k);
    cout<<res<<"\n";
}

signed main(){
    int t;cin>>t;
    Init(N-1);
    while(t--){
        solve();
    }
}