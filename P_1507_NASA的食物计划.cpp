#include <bits/stdc++.h>
using namespace std;

signed main(){
    int H,T;cin>>H>>T;
    int n;cin>>n;
    vector<int> h(n+1),t(n+1),K(n+1);
    vector<vector<int>> dp(H+1,vector<int>(T+1,0));

    for(int i=1;i<=n;++i){
        cin>>h[i]>>t[i]>>K[i];
    }

    for(int i=1;i<=n;++i){
        for(int j=H;j>=h[i];--j){
            for(int k=T;k>=t[i];--k){
                dp[j][k] = max(dp[j][k] , dp[j-h[i]][k-t[i]]+K[i]);
            }
        }
/**
        for(int j=1;j<=H;++j){
            for(int k=1;k<=T;++k){
                cerr<<dp[j][k]<<" ";
            }cerr<<endl<<endl;
        } */
    }

    cout<<dp[H][T]<<endl;
    return 0;
}