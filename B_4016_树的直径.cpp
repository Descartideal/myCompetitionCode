#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}


signed main(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist(n+1,-1);
    
    auto dfs = [&](int x){
        queue<int> q;
        q.push(x);
        dist[x] = 0;
        while(!q.empty()){
            int u = q.front();q.pop();
            for(auto y:g[u]){
                if(dist[y]==-1){
                    dist[y] = dist[u]+1;
                    q.push(y);
                }
            }
        }

        return max_element(dist.begin(),dist.end())-dist.begin();
    };

    int s = dfs(1);
    //cerr<<dist<<endl;
    fill(dist.begin(),dist.end(),-1);

    int e = dfs(s);
    //cerr<<dist<<endl;

    cout<<dist[e]<<endl;

    return 0;
}