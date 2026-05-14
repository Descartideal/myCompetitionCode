#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    string s;cin>>s;
    string t="0";
    char last = '0';
    for(int i=0;i<n;++i){
        char c = s[i];
        if(c==last)continue;
        t.push_back(c);
        last = c;
    }
    n = (int)t.size()-1;

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 1;
    }
    for(int i=1;i<=n-1;++i){
        dp[i][i+1] = 2;
    }

    for(int len=3;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            dp[l][r] = min(dp[l+1][r],dp[l][r-1])+1;
            if(t[l]==t[r])dp[l][r]=min({dp[l][r], dp[l][r-1]});
            for(int k=l;k+1<=r;++k){
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
            }
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}