#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

ll lowbit(int x){
    return x&(-x);
}

ll f(ll s,ll n){
    ll mi = (s-1)/n+1;
    bitset<64> t(mi);
    ll high = -1;
    for(int i=62;i>=0;--i){
        if(high==-1 && t[i]==1){
            high = i;
        }
        if(t[i]==0 && t[i+1]==1){
            t[i] = 1;
        }
    }
    ll mx = t.to_ullong();
    ll y = (1LL<<high);
    ll res;
    if(s/y>n){
        s -= n*y;
    }else{
        s -= (s/y)*y;
    }
    return y+(s!=0?f(s,n):0);

}

void solve(){
    int n;cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    ll s = accumulate(a.begin()+1,a.end(),0LL);

    if(s==0){
        cout<<0<<endl;
        return;
    }

    ll res2 = f(s,n);


    ll q=s/n,r=s%n;
    if(r)q++;
    ll res1=q;

    ll res = res1;


    if(res1!=res2){
        if(lowbit(s)<lowbit(res1)){
            res=res2;cerr<<8<<endl;
        }
    }

    cout<<res2<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}