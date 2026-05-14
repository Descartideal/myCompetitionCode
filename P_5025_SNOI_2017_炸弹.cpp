#include <bits/stdc++.h>
using namespace std;
#define int long long


template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}



const int M = 1e9+7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }

    cerr<<a<<endl<<endl;

    int ans = 0;
    for(int i=0;i<n;++i){
        int l,r,ll,rr;
        l = a[i]-b[i] , r = a[i]+b[i];
        ll = lower_bound(a.begin(),a.end(),l)-a.begin();
        auto it = upper_bound(a.begin(),a.begin(),r);
        if(it==a.end()){
            rr = n;
        }
        cerr<<l<<" "<<r<<endl;
        cerr<<ll<<" "<<rr<<endl<<endl;
        int t = rr - ll + 1;

        ans += t; ans%=M;
    }

    cout<<ans<<endl;
}