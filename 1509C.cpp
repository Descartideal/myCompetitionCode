#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 0;
    }
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j = i+len-1;
            dp[i][j] = min(dp[i+1][j]+(a[j]-a[i]), dp[i][j-1]+(a[j]-a[i]));
        }
    }
    cout<<dp[1][n]<<endl;
 
    return 0;
}