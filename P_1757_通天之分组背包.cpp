#include <bits/stdc++.h>
using namespace std;

signed main(){
    int m,n;cin>>m>>n;
    vector<vector<pair<int,int>>> group(10005);
    for(int i=1;i<=n;++i){
        int w,v,g;cin>>w>>v>>g;
        group[g].push_back({w,v});
    }
    vector<int> dp(m+1,0);

    for(auto g:group){
        if(g.empty())continue;

        auto old = dp;
        for(auto [w,v]:g){
            for(int j=m;j>=w;--j){
                dp[j] = max(dp[j] , old[j-w]+v);
            }
        }
    }
    cout<<dp[m]<<endl;


    return 0;
}