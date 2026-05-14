#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,r;cin>>n>>m>>r;
    vector<vector<int>> g(n+1);

    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> siz(n+1,0),top(n+1,0),dep(n+1,0),fa(n+1,0),hson(n+1,0);

    function<int(int,int,int)> dfs;
    dfs = [&](int x,int f,int deep){
        if(!top[x])top[x]=x;
        fa[x] = f;
        dep[x] = deep;
        int size = 1;
        int max_son=0,son_siz=0,max_son_siz=0;
        for(int y:g[x]){
            if(y==f)continue;
            son_siz = dfs(y,x,deep+1);
            if(son_siz>max_son_siz){
                max_son=y;
                max_son_siz=son_siz;
            }
            size += son_siz;
        }
        if(max_son){
            hson[x]=max_son;
            top[ max_son ] = top[x];
        }
        siz[x] = size;
        return size;
    };
    dfs(r,0,1);

    function<int(int)> t;
    t = [&](int x){
        if(top[x]==top[ top[x] ]){
            return top[x];
        }else{
            top[x]=t(top[x]);
            return top[x];
        }
    };

    for(int i=1;i<=m;++i){
        int x,y;cin>>x>>y;

        while(t(x)!=t(y)){
            if(dep[t(x)]>dep[t(y)])swap(x,y);
            y=fa[ t(y) ];if(y==0)y=r;
        }
        if(dep[x]>dep[y])swap(x,y);
        cout<<x<<endl;
    }

    return 0;
}