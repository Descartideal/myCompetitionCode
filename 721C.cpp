#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;


signed main(){
    int n,m,T;cin>>n>>m>>T;
    vector<vector<pii>> g(n+1);

    for(int i=1;i<=n;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    


    return 0;
}