#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
int n,m;
vector<vector<pii>>g;
int dp[105][105][26];

int dfs(int x,int y,int c){
    int &res = dp[x][y][c];
    if(res != -1)return res;

    res = 0;
    for(auto [nx,ch]:g[x]){
        if(ch<c)continue;
        if(!dfs(y,nx,ch)){
            res = 1;
            break;
        }
    }
    return res;
}

signed main(){
    cin>>n>>m;
    g.assign(n+1,{});
    for(int i=0;i<m;++i){
        int u,v;
        char ch;
        cin>>u>>v>>ch;
        g[u].push_back({v,ch-'a'});
    }

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<(dfs(i,j,0)?'A':'B');
        }
        cout<<'\n';
    }
    
    return 0;
}