#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}


signed main(){
    int n=readint(),m=readint();
    vector<vector<int>> g(n+1);
    //vector<unordered_map<int,int>> t(n+1);
    //vector<int> indeg(n+1,0),outdeg(n+1,0);

    for(int i=1;i<=m;++i){
        int u=readint(),v=readint();
        g[u].push_back(v);
        g[v].push_back(u);
        //t[u][v]++;
        //t[v][u]++;

        //outdeg[u]++;
        //indeg[v]++;
    }


    int stateCnt = 0;
    vector<int> w(n+1,0);
    function<void(int)> dfs;
    dfs = [&](int x){//cerr<<x<<endl;
        for(int y:g[x]){
            if(w[y]==0){
                w[y] = stateCnt;
                dfs(y);
            }
        }
    };

    queue<int> q;
    auto bfs = [&](int x){
        q.push(x);w[x] = stateCnt;

        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:g[u]){
                if(w[v]==0){
                    w[v] = stateCnt;
                    q.push(v);
                }
            }
        }
    };

    
    for(int i=1;i<=n;++i){
        if(w[i]==0){
            stateCnt++;
            w[i] = stateCnt;
            bfs(i);
        }
    }

    //d(stateCnt);

    cout<<m+2*stateCnt-n-1<<endl;




    return 0;
}