#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define int ll
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr

const ll N = 2e6+10;
signed prime[N+10],phi[N+10],pcnt;
bool vis[N+10];
ll f[N+10],fSum[N+10];
map<ll,ll> FMp;

void Sieve(int n,int p){
    phi[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            phi[i] = i-1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = i*p;
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

ll T(ll t,ll p){
    i128 n = t;
    return ( (n*(n+1)/2)%p) * ((n*(n+1)/2)%p )%p;
}

ll T3(ll n,ll p){
    i128 t = n;
    i128 res = t*(t+1)*(2*t+1)/6;
    res %= p;
    return res;
}

ll S(ll t,ll p){
    i128 n = t;
    return (n*(n+1)/2)%p;
}

ll F(ll n,ll p){
    if(n>=N){//cerr<<n<<" "<<p<<endl;
        if(FMp[n])return FMp[n];
        if(FMp[n-1])return FMp[n]=FMp[n-1]+f[n];
        if(FMp[n+1])return FMp[n]=FMp[n+1]-f[n+1];

        ll ans = T(n,p);
        for(ll l=2,r;l<=n;l=r+1){
            ll dn = n/l;
            r = n/dn;
            ans -= (T3(r,p)-T3(l-1,p))*F(dn,p);
            ans %= p;
        }
        //d(ans);
        return FMp[n] = ans;
    }else{
        return fSum[n];
    }
}

void Init(int n,int p){
    Sieve(n,p);
    for(int i=1;i<=n;++i){
        f[i] = i*i*phi[i]%p;
    }
    for(int i=1;i<=n;++i){
        fSum[i] = fSum[i-1]+f[i];
        fSum[i] %= p;
    }

}

//1 13 58 186 411 951 1588 2868 4569 7269

signed main(){
    ll p,n;cin>>p>>n;
    Init(min(N,n),p);
/**
    for(int i=1;i<=10;++i){
        cerr<<prime[i]<<" ";
    }cerr<<endl;

    for(int i=1;i<=10;++i){
        cerr<<phi[i]<<" ";
    }cerr<<endl;

    for(int i=1;i<=10;++i){
        cerr<<f[i]<<" ";
    }cerr<<endl;

    for(int i=1;i<=10;++i){
        cerr<<fSum[i]<<" ";
    }cerr<<endl;
 */
    ll res = 0;
    for(ll l=1,r;l<=n;l=r+1){
        ll dn = n/l;
        r = n/dn;
        if(r==n)cerr<<"asdf:"<<res<<endl;
        res += ((F(r,p)-F(l-1,p))*S(dn,p)%p)*S(dn,p)%p;
        if(r==n)cerr<<"fda:"<<res<<endl;

        d(  ((F(r,p)-F(l-1,p))*S(dn,p)%p)*S(dn,p)%p  );
        res %= p;
        d(l);d(r);
        d(S(dn,p));
        d(F(l-1,p));d(F(r,p));
        d(res);cerr<<endl;
    }
    res = (res%p+p)%p;

    cout<<res<<"\n";
}