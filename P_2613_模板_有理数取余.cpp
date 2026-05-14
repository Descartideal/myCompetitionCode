#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 19260817;

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll d = exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t-(a/b)*y;
    return d;
}

int main(){
    string aa,bb;cin>>aa>>bb;
    ll a=0,b=0;
    for(int i=0;i<aa.size();++i){
        char c = aa[i];
        int t = c-'0';
        a = (a*10+t)%M;
    }
    for(int i=0;i<bb.size();++i){
        char c = bb[i];
        int t = c-'0';
        b = (b*10+t)%M;
    }
    
    ll x,y;
    ll d = exgcd(b,M,x,y);
    x = (x%M+M)%M;
    x = x/d*a%M;
    cout<<x<<endl;
    return 0;
}