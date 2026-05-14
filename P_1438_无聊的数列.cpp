#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll lowbit(ll x){
    return x & -x;
}

void change(ll pos,ll da,ll n,vector<ll>& re){
    for(;pos<=n;pos+=lowbit(pos)){
        re[pos]+=da;
    }
}

ll presum(ll pos,vector<ll>& re){
    ll ans = 0;
    for(;pos;pos-=lowbit(pos)){
        ans+=re[pos];
    }
    return ans;
}

int main(){
    int n,m;cin>>n>>m;
    vector<ll> a(n+3,0);for(int i=1;i<=n;++i){cin>>a[i];}
    vector<ll> b(n+3,0);for(int i=1;i<=n;++i){b[i]=a[i]-a[i-1];}
    vector<ll> c(n+3,0);for(int i=1;i<=n;++i){c[i]=b[i]-b[i-1];}

    vector<ll> cr(n+3,0);
    vector<ll> icr(n+3,0);

    for(int i=1;i<=n;++i){
        change(i,c[i],n,cr);
    }
    for(int i=1;i<=n;++i){
        change(i,i*c[i],n,icr);
    }

    auto f = [&](ll pos,ll d){
        change(pos,d,n,cr);
        change(pos,d*pos,n,icr);
    };


    for(int i=1;i<=m;++i){
        int e;cin>>e;
        if(e==1){
            ll l,r,k,d;cin>>l>>r>>k>>d;
            ll cnt = r-l+1;
            k=k-d;
            f(l,d);f(r+1,-d);
            f(r+1,-d*cnt);f(r+2,d*cnt);

            f(l,k);f(l+1,-k);
            f(r+1,-k);f(r+2,k);
        }else{
            int p;cin>>p;
            cout<<(p+1)*presum(p,cr)-presum(p,icr)<<endl;
        }

    }
    return 0;
}