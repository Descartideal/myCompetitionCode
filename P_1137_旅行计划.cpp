#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1,0);
    vector<int> dp(n+1,1);

    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    
    queue<int>q;
    for(int i=1;i<=n;++i){
        if(indeg[i]==0)q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:g[u]){
            dp[v] = max(dp[v],dp[u]+1);
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }

    for(int i=1;i<=n;++i){
        cout<<dp[i]<<'\n';
    }

    return 0;
}