#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;


signed main(){
    int n;cin>>n;
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    


    return 0;
}