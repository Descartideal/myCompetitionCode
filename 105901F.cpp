#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

const ll M = 998244353;

void print(i128 x){
    vector<int> a;
    while(x){
        a.push_back(x%10);
        x/=10;
    }
    string s;
    for(int i=a.size()-1;i>=0;--i){
        cerr<<a[i];
    }
}

ll pow(ll a,ll b){
    b%=M;
    ll x = a; x%=M;
    ll res = 1LL;
    while(b){
        if(b&1){
            res *= x;
            res%=M;
        }
        x=x*x;x%=M;
        b>>=1;
    }
    return res;
}


void solve(){
    cout<<pow(2,)<<endl;
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> a;
    for(int i=1;i<=n;++i){
        ll u,v;cin>>u>>v;
        a.push_back({v,u});
    }
    sort(a.begin(),a.end());

    vector<pair<ll,ll>> b(n,{0LL,0LL});

    i128 remain = 0;
    {
        ll p = a[n-1].first , cnt = a[n-1].second;
        b[n-1].second = p;
        b[n-1].first = (cnt-1)/m+1;
        remain = b[n-1].first*m - cnt;
    }

    
    for(int i=n-2;i>=0;--i){
        ll p = a[i].first , cnt = a[i].second;

        //cerr<<p<<" "<<cnt<<" ";
        //print(remain);cerr<<endl;

        if(b[i+1].second-p>=80){
            break;
        }
        remain <<= b[i+1].second-p;

        if(remain>=cnt){
            remain -= cnt;
            continue;
        }else if(remain<cnt){
            remain = 0;
            cnt -= remain;
        }

        b[i].second = p;
        b[i].first = (cnt-1)/m+1;
    }

/** 
    for(int i=0;i<n;++i){
        cout<<b[i].first<<" "<<b[i].second<<endl;
    }cout<<endl;
*/

    ll ans = 0;
    for(int i=0;i<n;++i){
        ll x=b[i].first,y=b[i].second;
        ll t = pow(2,y);
        cerr<<y<<" "<<t<<endl;
        t*=x;t%=M;
        
        ans+=t;ans%=M;
    }
    cout<<ans<<endl;
   
    return;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}