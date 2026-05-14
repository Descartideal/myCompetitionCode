#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s;cin>>s;
    int n = (int)s.size();
    s = ' '+s;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    auto digits = [&](int x){
        return (int)to_string(x).size();
    };

    auto is_repeat = [&](int l,int r,int p){
        int len = r-l+1;
        if(len%p!=0)return false;
        for(int i=0;i<len;++i){
            if(s[l+i]!=s[l+(i%p)])return false;
        }
        return true;
    };

    for(int len=1;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            dp[l][r] = len;

            for(int k=l;k<r;++k){
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
            }

            for(int p=1;p<len;++p){
                if(len%p!=0)continue;
                if(is_repeat(l,r,p)){
                    int cnt = len/p;
                    dp[l][r] = min(dp[l][r], dp[l][l+p-1]+2+digits(cnt));
                }
            }
        }
    }
    cout<<dp[1][n]<<'\n';

    return 0;
}