#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n+1,0),ct(n+1,1),fa(n+1,0);

    function<int(int,int)> dfs;
    dfs = [&](int x,int dist){
        int sum = dist;
        for(int y:g[x]){
            if(y==fa[x])continue;
            fa[y] = x;
            sum += dfs(y,dist+1);
            ct[x] += ct[y];
        }
        return sum;
    };

    d[1] = dfs(1,0);

    function<int(int)> f;
    f = [&](int x){
        for(int y:g[x]){
            if(y==fa[x])continue;
            d[y] = d[x] + (n-ct[y]) -ct[y];
            f(y);
        }
        return 0;
    };

    f(1);

    int res = 0,mi = INT_MAX;
    for(int i=1;i<=n;++i){
        if(mi>d[i]){
            mi = d[i];
            res = i;
        }
    }

    cout<<res<<" "<<mi<<endl;

    return 0;
}