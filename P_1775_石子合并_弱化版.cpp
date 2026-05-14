#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i] = pre[i-1]+a[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 0;
    }
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j = i+len-1;
            
            int s = pre[j]-pre[i-1];
            for(int k=i;k+1<=j;++k){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+s);
            }
        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}