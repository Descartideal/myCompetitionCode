#include <bits/stdc++.h>
using namespace std;

const int N = 300+10;
const int INF = 1e9;

int n,m;
int s[N],sz[N],dp[N][N];
vector<int> g[N];

void dfs(int x){
    sz[x] = 1;
    dp[x][1] = s[x];
    for(int i=2;i<=N;++i){
        dp[x][i]=-INF;
    }

    for(int y:g[x]){
        dfs(y);
        for(int j=sz[x]+sz[y];j>=2;--j){
            for(int k=0;k<=j-1;++k){
                dp[x][j] = max(dp[x][j], dp[x][j-k]+dp[y][k]);
            }
        }
        sz[x]+=sz[y];
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int u,score;cin>>u>>score;
        g[u].push_back(i);
        s[i] = score;
    }
    

    dfs(0);
    cout<<dp[0][m+1]<<endl;
    return 0;
}