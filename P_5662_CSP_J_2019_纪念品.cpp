#include <bits/stdc++.h>
using namespace std;

signed main(){
    int T,n,M;cin>>T>>n>>M;
    vector<vector<int>> p(T+1,vector<int>(n+1,0));
    for(int i=1;i<=T;++i){
        for(int j=1;j<=n;++j){
            cin>>p[i][j];
        }
    }

    for(int i=1;i<=T-1;++i){
        vector<int> w(n+1),v(n+1);
        for(int j=1;j<=n;++j){
            w[j] = p[i][j];
            v[j] = p[i+1][j]-p[i][j];
        }

        vector<int> dp(M+1,0);
        for(int j=1;j<=n;++j){
            for(int k=w[j];k<=M;++k){
                dp[k] = max(dp[k],dp[k-w[j]]+v[j]);
            }
        }

        M += dp[M];
    }
    cout<<M<<endl;

    return 0;
}