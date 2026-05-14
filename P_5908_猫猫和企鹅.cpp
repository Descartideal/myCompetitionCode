#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

int main(){
    int n,d;cin>>n>>d;
    vector<vector<int>> g(n+1);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n+1,0);
    queue<pii> q;q.push({1,d});
    while (!q.empty()) {
        auto [x,c] = q.front();q.pop();
        

        if(c==0)continue;

        for(int y:g[x]){
            if(vis[y]==0){
                q.push({y,c-1});
                vis[y] = 1;
            }
        }
    }

    int res = 0;
    for(int i=2;i<=n;++i){
        if(vis[i]==1){
            ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}