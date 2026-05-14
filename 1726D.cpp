#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

void solve(){
    srand(time(0));
    int n,m;cin>>n>>m;
    vector<vector<pii>> g(n+1);
    vector<pii> eg(m+1);
    vector<int> deg(n+1,0);
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        eg[i] = {u,v};
        deg[u]++;
        deg[v]++;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=1;i<=n;++i){
        shuffle(g[i].begin(), g[i].end(), rng);
    }
    

    vector<int> w(n+1,0);
    vector<int> color(m+1,0);
    function<void(int)> dfs;
    dfs = [&](int x){
        w[x]=1;
        for(auto [y,dex]:g[x]){
            if(w[y]==1)continue;
            color[dex]=1;
            dfs(y);
        }
    };

    auto bfs = [&](int x){
        queue<int> q;q.push(x);
        w[x]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto [v,dex]:g[u]){
                if(w[v])continue;
                w[v]=1;
                color[dex]=1;
                q.push(v);
            }
        }
    };
    /** 
    int strat = 1;
    for(int i=1;i<=n;++i){
        if(deg[i]%2==0){
            strat = i;
            break;
        }
    }
    */
    if(rng()&1){
        dfs(rng()%n+1);
    }else{
        bfs(rng()%n+1);
    }
    
 
    if(m==n+2){
        set<int> t;
        for(int i=1;i<=m;++i){
            if(color[i]==0){
                t.insert(eg[i].first);
                t.insert(eg[i].second);
            }
        }
        while(t.size()==3){
        /** 
            vector<int> tt;;
            for(int x:t){
                tt.push_back(x);
            }
        */
            fill(w.begin(),w.end(),0);
            fill(color.begin(),color.end(),0);
            if(rng()%5==1){
                dfs(rng()%n+1);
            }else{
                bfs(rng()%n+1);
            }

            t.clear();
            for(int i=1;i<=m;++i){
                if(color[i]==0){
                    t.insert(eg[i].first);
                    t.insert(eg[i].second);
                }
            }
        }
    }


    string s="";
    for(int i=1;i<=m;++i){
        s+=to_string(color[i]);
    }
    cout<<s<<"\n";
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}