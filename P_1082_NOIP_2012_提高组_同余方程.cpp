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

inline ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

signed main(){
    ll a=readint(),b=readint(),x,y;
    ll d=exgcd(a,b,x,y);
    x=(x%b+b)%b;
    cout<<x;
    return 0;
}