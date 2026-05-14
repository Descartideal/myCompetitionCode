#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,sz;
    DSU(int n=0){init(n);}
    void init(int n){
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y);
        fa[y]=x;
        sz[x]+=sz[y];
        return true;
    }
};

struct Edge{
    int u,v,w;
    bool operator<(const Edge& o)const{return w<o.w;}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<Edge> edges;
    edges.reserve(1LL*n*(n-1)/2);

    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j){
        int x;cin>>x;
        a[i][j]=a[j][i]=x;
        edges.push_back({i,j,x});
    }
    sort(edges.begin(),edges.end());
    DSU dsu(n);
    vector<vector<pair<int,int>>> g(n+1);

    int cnt=0;
    for(auto&e:edges)if(dsu.unite(e.u,e.v)){
        g[e.u].push_back({e.v,e.w});
        g[e.v].push_back({e.u,e.w});
        if(++cnt==n-1)break;
    }

    vector<long long> dist(n+1);
    auto dfs=[&](auto&& self,int u,int fa)->void{
        for(auto[v,w]:g[u])if(v!=fa){
            dist[v]=dist[u]+w;
            self(self,v,u);
        }
    };

    for(int s=1;s<=n;++s){
        fill(dist.begin(),dist.end(),0);
        dfs(dfs,s,0);
        for(int t=s+1;t<=n;++t){
            if(dist[t]!=a[s][t]){
                cout<<"No\n";
                return 0;
            }
        }
    }

    cout<<"Yes\n";
    return 0;
}