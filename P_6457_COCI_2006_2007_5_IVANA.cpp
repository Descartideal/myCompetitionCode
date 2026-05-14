#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> a(2*n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]%=2;
        a[i+n]=a[i];
    }

    vector<vector<int>> dp(2*n+1,vector<int>(2*n+1,0));
    for(int i=1;i<=2*n;++i){
        dp[i][i] = a[i];
    }

    for(int len=2;len<=n-1;len++){
        for(int l=1;l+len-1<=2*n;++l){
            int r = l+len-1;
            dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
        }
    }

    int ans = 0;
    for(int s=1;s<=n;++s){
        int diff = a[s]-dp[s+1][s+n-1];
        if(diff>0)ans++;
    }

    cout<<ans<<endl;
    return 0;
}