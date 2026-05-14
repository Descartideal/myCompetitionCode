#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

#define int long long

struct y{
    int t,w;
};

signed main(){
    int t,m;cin>>t>>m;
    vector<y> a(m+1);
    for(int i=1;i<=m;++i){
        cin>>a[i].t>>a[i].w;
    }

    vector<int> dp(t+1,0);
    for(int i=1;i<=m;++i){
        //cerr<<dp<<endl;
        for(int j=a[i].t;j<=t;++j){
            dp[j] = max(dp[j] , dp[j-a[i].t]+a[i].w);
        }
        //cerr<<dp<<endl<<endl;
    }
    cout<<dp[t]<<endl;

    return 0;
}