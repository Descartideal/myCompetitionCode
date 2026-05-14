#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n,M,T;cin>>n>>M>>T;
    vector<int> m(n+1),t(n+1);
    for(int i=1;i<=n;++i){
        cin>>m[i]>>t[i];
    }

    vector<vector<int>> dp(M+1,vector<int>(T+1));
    for(int i=1;i<=n;++i){
        for(int j=M;j>=m[i];--j){
            for(int k=T;k>=t[i];--k){
                dp[j][k] = max(dp[j][k] , dp[j-m[i]][k-t[i]]+1);
            }
        }
    }

    cout<<dp[M][T]<<endl;

    return 0;
}