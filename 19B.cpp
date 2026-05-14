#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<62;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<int> t(n+1);
    vector<ll> c(n+1);

    for(int i=1;i<=n;++i){
        cin>>t[i]>>c[i];
    }
    vector<ll> dp(n+1,INF);
    dp[0] = 0;

    for(int i=1;i<=n;++i){
        int w = t[i]+1;
        for(int j=n;j>=0;--j){
            if(dp[j]==INF)continue;
            int nj = min(n,j+w);
            dp[nj] = min(dp[nj],dp[j]+c[i]);
        }
    }

    cout<<dp[n]<<'\n';
    return 0;
}