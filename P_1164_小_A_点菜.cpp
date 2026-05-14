#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

#define int long long


signed main(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,0);for(int i=1;i<=n;++i){cin>>a[i];}
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i){
        dp[i] = dp[i-1];
        if(a[i]>m)continue;
        dp[i][ a[i] ] = dp[i-1][ a[i] ]+1;
        for(int j=(a[i]+1);j<=m;++j){
            dp[i][j] = dp[i-1][j]+dp[i-1][ j-a[i] ];
        }
        //cerr<<a[i]<<" "<<dp[i]<<endl;
    }

    cout<<dp[n][m]<<endl;

    return 0;
}