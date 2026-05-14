#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

#define int long long

using pii = pair<int,int>;
using umii = unordered_map<int,int>;
const int INF = 1e14+7;

signed main(){
    int N,M,C;cin>>N>>M>>C;
    vector<int> S(N+1,0);
    for(int i=1;i<=N;++i){
        cin>>S[i];
    }

    vector<umii> g(N+1);
    vector<vector<int>> h(N+1);
    for(int i=1;i<=C;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u][v] = max(g[u][v],w);
        h[v].push_back(u);
    }
    

    vector<int> dp(N+1,INF);

    function<void(int)> dfs;
    dfs = [&](int x){
        int res = S[x];
        for(int y:h[x]){
            if(dp[y]==INF)dfs(y);
            res = max(dp[y]+g[y][x],res);
        }
        dp[x] = res;
    };

    for(int i=1;i<=N;++i){
        if(dp[i]==INF)dfs(i);
    }

    for(int i=1;i<=N;++i){
        cout<<dp[i]<<endl;
    }

    return 0;
}