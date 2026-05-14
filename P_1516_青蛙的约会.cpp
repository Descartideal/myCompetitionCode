#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floor_div(ll a,ll b){
    return (a/b)-((a^b)<0 && (a%b!=0));
}

ll mgcd(ll a,ll b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mgcd(b%a,a);
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

int main(){
    ll x0,y0,m,n,L;cin>>x0>>y0>>m>>n>>L;
    m%=L;n%=L;
    x0%=L;y0%=L;
    ll a=(m-n);a = (a+L)%L;
    ll c = y0-x0;c=(c%L+L)%L;
    ll x,y;
    ll d = exgcd(a,L,x,y);
    if(c%d!=0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    x=x*(c/d);
    ll tx=L/d;
    ll k=floor_div(x-1,tx);
    x -= tx*k;x%=L;
    cout<<x<<endl;
    return 0;
}