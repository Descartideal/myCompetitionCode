#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(1,0));
    for(int i=1;i<=n;++i){
        int cnt;cin>>cnt;
        for(int j=1;j<=cnt;++j){
            int x;cin>>x;
            g[i].push_back(x);
        }
    }

    vector<vector<int>> h(n+1,vector<int>(1,0));
    vector<vector<int>> pre(n+1,vector<int>(1,0)),surf(n+1,vector<int>(1,0));
    for(int i=1;i<=n;++i){
        int len = g[i].size()-1;

        for(int j=1;j<=len;++j){
            pre[i].push_back(pre[i][j-1]+g[i][j]);
        }
        for(int j=len;j>=1;--j){
            surf[i].push_back(surf[i][len-j]+g[i][j]);
        }
    }

    for(int i=1;i<=n;++i){
        int len = g[i].size()-1;
        for(int j=1;j<=len;++j){
            int ans = 0;
            for(int k=0;k<=j;++k){
                ans = max(ans,pre[i][k]+surf[i][j-k]);
            }
            h[i].push_back(ans);
        }
    }

    vector<int> dp(m+1,0);
    for(int i=1;i<=n;++i){
        auto old = dp;
        int len = g[i].size()-1;
        for(int j=1;j<=len;++j){
            int w=j,v=h[i][j];
            
            for(int k=m-w;k>=0;--k){
                dp[k+w] = max(dp[k+w],old[k]+v);
            }
        }
    }
    cout<<dp[m]<<endl;

    return 0;
}