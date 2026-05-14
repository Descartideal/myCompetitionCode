#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=k*10+(c&15);
    return k*f;
}

ll mpow(ll a,ll b,ll m){
    ll res=1;a%=m;
    while(b){
        if(b&1){
            res*=a;res%=m;
        }
        a=a*a;a%=m;
        b>>=1;
    }
    return res;
}

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll d = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - (a/b)*y;
    return d;
}

ll inv(ll a,ll p){
    ll x,y;
    exgcd(a,p,x,y);
    x = (x%p+p)%p;
    return x;
}

signed main(){
    ll n=readint(),p=readint(),k=readint();

    vector<ll> a(n+1);
    for(int i=1;i<=n;++i){
        a[i]=readint();
    }
    vector<ll> s(n+1,1);
    for(int i=1;i<=n;++i){
        s[i] = s[i-1]*a[i]%p;
    }
    vector<ll> surf(n+2,1);
    for(int i=n;i>=1;--i){
        surf[i] = surf[i+1]*a[i]%p;
    }
    ll s_inv = inv(s[n],p);


    ll ans = 0,pw=1;
    for(int i=1;i<=n;++i){
        pw*=k;pw%=p;
        ll x = s[i-1]*surf[i+1]%p*s_inv%p;
        ans += pw*x%p;
        ans %= p;
    }
    cout<<ans<<endl;

    return 0;
}