#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}


const int M = 1e6+7;

signed main(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i] = a[i]+pre[i-1];
    }

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;++i){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int k=0;k<=min(j,a[i]);++k){
                dp[i][j] = (dp[i][j]+dp[i-1][j-k])%M;
            }
        }

        //cerr<<dp[i]<<endl;
    }
    cout<<dp[n][m]<<endl;

    return 0;
}