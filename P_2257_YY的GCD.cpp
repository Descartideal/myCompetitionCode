#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 10000000;

int T;
int mu[MAXN+5];
bool vis[MAXN+5];
int prime[700000],pcnt;

int f[MAXN+5];
int sumf[MAXN+5];

pair<int,int> qs[10005];

void linearSieveMu(int n){
    mu[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            mu[i] = -1;
        }
        for(int j=1;j<=pcnt;++j){
            int p  = prime[j];
            if((ll)i*p>n)break;
            vis[i*p] = true;
            if(i%p==0){
                mu[i*p] = 0;
                break;
            }else{
                mu[i*p] = -mu[i];
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    int mx = 0;
    for(int i=1;i<=T;++i){
        int u,v;cin>>u>>v;
        if(u>v)swap(u,v);
        qs[i] = {u,v};
        mx = max(mx,u);
    }

    linearSieveMu(mx);

    for(int i=1;i<=pcnt;++i){
        int p = prime[i];
        if(p>mx)break;
        for(int d = 1;(ll)p*d<=mx;++d){
            f[p*d] += mu[d];
        }
    }

    for(int i=1;i<=mx;++i){
        sumf[i] = sumf[i-1]+f[i];
    }

    for(int i=1;i<=T;++i){
        int u = qs[i].first;
        int v = qs[i].second;

        ll ans = 0;
        int limit = u;
        for(int l=1,r;l<=limit;l=r+1){
            int du = u/l;
            int dv = v/l;
            r = min(u/du,v/dv);
            ans += (ll)(sumf[r]-sumf[l-1])*du*dv;
        }
        cout<<ans<<"\n";
    }

    return 0;
}