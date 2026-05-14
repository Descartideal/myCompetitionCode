#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+a[i];
    }
    auto s = [&](int a,int b){
        return pre[b]-pre[a-1];
    };


    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;++i){
        dp[i][i] = a[i];
    }

    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j = i+len-1;
            dp[i][j] = max(dp[i][j-1]+s(i,j), dp[i+1][j]+s(i,j));
        }
    }
    
    cout<<dp[1][n]<<endl;
    return 0;
}