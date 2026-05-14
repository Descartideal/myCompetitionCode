#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;

#define double long double

int n,m;
vector<pair<int,int>> g[N];
double f[N];
bool vis[N];

double dfs(int u){
    if(vis[u])return f[u];
    vis[u] = true;
    if(u==n)return f[u]=0.0;
    double sum=0.0;
    for(auto [v,w]:g[u]){
        sum += w+dfs(v);
    }
    return f[u]=sum/g[u].size();
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    cout<<fixed<<setprecision(2)<<dfs(1)<<"\n";
    return 0;
}