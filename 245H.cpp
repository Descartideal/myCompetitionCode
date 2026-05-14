#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s;cin>>s;
    int n = s.size();
    s = " "+s;

    vector<vector<int>> dp(n+1,vector<int>(n+1,0)),pal(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i){
        dp[i][i] = 1;
        pal[i][i] = 1;
    }
    for(int i=1;i<=n-1;++i){
        if(s[i]==s[i+1])pal[i][i+1]=1;
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            if(pal[l+1][r-1])pal[l][r]=(s[l]==s[r]);

            dp[l][r] = dp[l][r-1]+dp[l+1][r]-dp[l+1][r-1]+pal[l][r];
        }
    }

    int q;cin>>q;
    for(int i=1;i<=q;++i){
        int l,r;cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }

    return 0;
}