#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int last = -1;
    vector<int> a(1,0);
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        if(x==last)continue;
        a.push_back(x);last=x;
    }
    n = (int)a.size()-1;

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 0;
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;
            dp[l][r] = min(dp[l+1][r], dp[l][r-1])+1;
            if(a[l]==a[r])dp[l][r]=min(dp[l+1][r-1]+1,dp[l][r]);
        }
    }

    cout<<dp[1][n]<<endl;
    return 0;
}