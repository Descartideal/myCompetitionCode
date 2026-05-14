#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif


int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k = k*10+(c&15);
    return k*f;
}

const int maxn=1e6;
const ll M = 998244353;

inline ll lowbit(ll x){return x&(-x);}

ll sum(ll k,const vector<ll>& a){
    ll s = 0;
    for(;k;k-=lowbit(k)){
        s+=a[k];
    }
    return s;
}

void updata(ll pos,ll val,vector<ll>& a,ll n){
    for(;pos<=n;pos+=lowbit(pos)){
        a[pos]+=val;
    }
}


void solve(){
    int n=readint(),k=readint();
    vector<ll> a(n+1,0),b(n+1,0);
    vector<pair<ll,ll>> c(n);
    set<ll> ls;
    for(int i=1;i<=n;++i){
        a[i]=readint();b[i]=readint();
        c[i-1].first=a[i];c[i-1].second=b[i];
        ls.insert(a[i]);ls.insert(b[i]);
    }
    sort(c.begin(),c.end());

    ll m = ls.size()+1;
    vector<ll> e(m+1,0);
    unordered_map<ll,ll> t;

    int cnt = 0;
    for(auto x:ls){
        //cerr<<"asdf:"<<x<<" "<<cnt<<endl;
        cnt++;
        t[x] = cnt;
    }

    vector<ll> ans;

    for(auto [l,r]:c){
        l=t[l],r=t[r];
        //cerr<<77<<" "<<l<<" "<<r<<endl;

        ll p = sum(l,e);
        //cerr<<"p:"<<p<<endl;
        if(p==0){
            ans.push_back(k);
            updata(1,1,e,m);
            updata(r+1,-1,e,m);
            continue;
        }
        ll q = max(0LL,k-p);
        ans.back()*=q;ans.back()%=M;
        updata(1,1,e,m);
        updata(r+1,-1,e,m);
    }

    ll res = 1;
    for(auto x:ans){
        res *= x;
        res%=M;
    }
    cout<<res<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t=readint();
    while (t--)
    {
        solve();
    }

    return 0;
}