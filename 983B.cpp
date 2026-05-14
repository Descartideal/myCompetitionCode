#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)),f(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i){
        dp[i][i] = a[i];
        f[i][i] = a[i];
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;
            f[l][r] = f[l][r-1]^f[l+1][r];

            dp[l][r] = max({dp[l][r-1],dp[l+1][r],f[l][r]});
        }
    }

    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }

    return 0;
}