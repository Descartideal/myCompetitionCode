#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using b64 = bitset<64>;

const ll M = 1000000007LL;

ll nrm(ll x){x%=M;if(x<0)x+=M;return x;}
ll mul(ll a,ll b){return (ll)((__int128)nrm(a)*nrm(b)%M);}

ll sum(ll l,ll r){
    if(l>r)return 0;
    ll a=nrm(l)+nrm(r);if(a>=M)a-=M;
    ll b=nrm(r-l+1);
    return mul(mul(a,b),500000004LL);
}

ll cd(ll a,ll b){
    if(b<0)a=-a,b=-b;
    if(a>=0)return (a+b-1)/b;
    return -((-a)/b);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);

    ll id,n,q;cin>>id>>n>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        b64 bl((ull)l),br((ull)r);
        ll sa=sum(l,r),sr=0,so=0,c=0;

        for(int k=0;k<=60;++k){
            ll p=1LL<<k,m=1LL<<(k+1);
            ll hi=l+p-1;if(hi>r)hi=r;

            if(hi<l)continue;
            ll kk=cd(l-p,m);
            ll x=kk*m+p;
            if(x<l||x>hi)continue;
            ++c;
            sr+=nrm(x);if(sr>=M)sr-=M;
            if(x!=l){
                ll v=((ull)l)|((ull)x);
                so+=v%M;if(so>=M)so-=M;
            }
        }

        ll ans=sa-sr;if(ans<0)ans+=M;
        ans+=so;if(ans>=M)ans-=M;
        ll add=0;

        for(int k=0;k<=60;++k){
            ull m=(1ULL<<(k+1)),mask=m-1;
            if(((ull)l&mask)!=0ULL)continue;
            ull x=(ull)l+(1ULL<<k);
            if(x<=(ull)r)++add;
        }

        ll deg=(c?c-1:0)+add;
        cout<<ans<<" "<<deg<<"\n";
    }

    return 0;
}