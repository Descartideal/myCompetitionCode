#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(2*n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];a[i+n]=a[i];
    }

    vector<vector<int>> dp(2*n+1,vector<int>(2*n+1,0));
    for(int i=1;i<=2*n-2;++i){
        dp[i][i+2] = a[i]*a[i+1]*a[i+2];
    }

    for(int len=2;len<=2*n-1;++len){
        for(int i=1;i+len<=2*n;++i){
            int j=i+len;
            for(int k=i+1;k<=j-1;++k){
                dp[i][j] = max(dp[i][j] , dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;++i){
        ans = max(ans,dp[i][i+n]);
    }
    cout<<ans;

    return 0;
}