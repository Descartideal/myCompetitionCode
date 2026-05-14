#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }



    return 0;
}