#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 1;
    }
    for(int i=1;i<=n-1;++i){
        if(a[i]==a[i+1]){
            dp[i][i+1]=1;
        }else{
            dp[i][i+1]=2;
        }
    }

    for(int len=3;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j = i+len-1;
            
            if(a[i]==a[j])dp[i][j] = dp[i+1][j-1];
            int ansMin = INF;
            for(int k=i;k+1<=j;++k){
                ansMin = min(ansMin, dp[i][k]+dp[k+1][j]);
            }
            dp[i][j] = min(ansMin,dp[i][j]);
        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}