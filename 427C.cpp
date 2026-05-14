#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5;
const int MOD = 1e9+7;

int n,m;
ll cost[N];
vector<int> g[N];

int dfn[N],low[N],idx;
bool in_stk[N];
stack<int> stk;

ll ans_sum=0;
ll ans_cnt=1;

void tarjan(int u){
    dfn[u] = low[u] = ++idx;
    stk.push(u);
    in_stk[u] = true;

    for(int v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(in_stk[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }

    if(dfn[u]==low[u]){
        ll mn = (ll)4e18;
        ll cnt = 0;

        while(true){
            int x = stk.top();
            stk.pop();
            in_stk[x]=false;

            if(cost[x]<mn){
                mn=cost[x];
                cnt = 1;
            }else if(cost[x]==mn){
                cnt++;
            }

            if(x==u)break;
        }

        ans_sum += mn;
        ans_cnt = ans_cnt*cnt%MOD;
    }
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>cost[i];

    cin>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;++i){
        if(!dfn[i])tarjan(i);
    }

    cout<<ans_sum<<" "<<ans_cnt<<"\n";
    return 0;
}