#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

using i128 = __int128;
map<int,ll> muMp;

/**
struct FastHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ull;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<ll,ll,FastHash> muMp;
*/

const int N = 2e6+10;
const ll M = 998244353;
int limit;

int pcnt,mu[N+10],prime[N+10],muPre[N+10];
bool vis[N+10];

inline void Sieve(int n){
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

inline void Init(int n){
    Sieve(n);
    for(int i=1;i<=n;++i){
        muPre[i] = mu[i]+muPre[i-1];
    }
}

int MuPre(int x){
    if(x<=limit){
        return muPre[x];
    }else{
        //if(muMp[x-1])return muMp[x]=muMp[x-1]+mu[x];
        //if(muMp[x+1])return muMp[x+1]=muMp[x]+mu[x+1];
        //if(muMp[x])return muMp[x];
        auto it = muMp.find(x);
        if(it != muMp.end())return it->second;

        int ans = 1;
        for(int l=2,r;l<=x;l=r+1){
            int dx = x/l;
            r = x/dx;
            ans -= (r-l+1)*MuPre(dx);
        }
        return muMp[x] = ans;
    }
}


signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    //muMp.reserve(1<<20);
    limit = (int)pow((ld)n,2.0L/3.0L) + 5;
    Init(limit);
    


    ll ans = 0;
    for(ll l=1,r;l<=n;l=r+1){
        ll dn = n/l;
        r = n/dn;
        
        ll t = (ll)(MuPre(r)-MuPre(l-1))*(dn)%M;
        t*=dn;t%=M;
        t*=dn;t%=M;

        ans += t;
        ans %= M;
    }

    ans = (ans%M+M)%M;
    ll res = ans;
    cout<<res<<endl;
}