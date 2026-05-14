#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int,int>;
using umii = unordered_map<int,int>;

signed main(){
    int n,p;cin>>n>>p;
    vector<vector<int>> h(n+1);
    vector<umii> g(n+1);
    vector<int> outdeg(n+1,0);

    vector<int> state(n+1,0),U(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>state[i]>>U[i];
    }

    for(int i=1;i<=p;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u][v] = w;
        h[v].push_back(u);
        outdeg[u]++;
    }

    vector<int> dp(n+1,-1);

    function<void(int)>dfs;
    dfs = [&](int x){
        int res = 0;
        for(int y:h[x]){
            if(dp[y]==-1)dfs(y);
            res += g[y][x] * dp[y];
        }
        res -= U[x];
        if(res<0)res=0;
        if(state[x]!=0)res=state[x];
        dp[x] = res;
    };



    for(int i=1;i<=n;++i){
        if(dp[i]==-1)dfs(i);
    }

    vector<pii> ans;

    for(int i=1;i<=n;++i){
        if(outdeg[i]==0){
            if(dp[i]>0)ans.push_back({i,dp[i]});
        }
    }

    int j = 0;
    for(auto [x,y]:ans){
        if(y==0)continue;
        else j=1;
    }

    if(j){
        for(auto [x,y]:ans){
            cout<<x<<" "<<y<<endl;
        }
    }else{
        cout<<"NULL"<<endl;
    }


    return 0;
}