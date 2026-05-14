#include "bits/stdc++.h"
using namespace std;
#define int long long

#define len (r-l+1)
#define lson (rt<<1),l,mid
#define rson (rt<<1|1),mid+1,r
#define mid ((l+r)>>1)


const int N = 2e5+10;


int edge_cnt=0,head[N],to[N],nex[N];//链式前向星数据
int n,siz[N],dep[N],id[N],val[N],fa[N],w[N],wt[N],son[N],top[N];//树的数据+树链剖分数据
int add[N<<2],lz[N<<2];//线段树数据



void add_edge(int u,int v){
    nex[++edge_cnt] = head[u];
    head[u] = edge_cnt;
    to[edge_cnt] = v;
}



//线段树start------
void push_down(int rt,int lenn){
    if(lz[rt]==0)return;
    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
    add[rt<<1]+=lz[rt]*(lenn-(lenn>>1));add[rt<<1|1]+=lz[rt]*(lenn>>1);
    lz[rt]=0;
}

void build(int rt,int l,int r){
    if(l==r){add[rt]=wt[l];return;}
    build(lson);build(rson);
    add[rt]=add[rt<<1]+add[rt<<1|1];
}

int query(int rt,int l,int r,int L,int R){
    if(R<L)swap(L,R);
    if(L<=l && r<=R){return add[rt];}
    int res=0;
    push_down(rt,len);
    if(L<=mid){res+=query(lson,L,R);}
    if(R>mid)res+=query(rson,L,R);
    return res;
}

void updata(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){add[rt] += k*len;lz[rt] += k;return;}
    push_down(rt,len);
    if(L<=mid)updata(lson,L,R,k);
    if(R>mid)updata(rson,L,R,k);
    add[rt] = add[rt<<1]+add[rt<<1|1];
}
//线段树end------

int qrange(int x,int y){
    int ans = 0;
    while (top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=query(1,1,n,id[top[x]],id[x]);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=query(1,1,n,id[x],id[y]);
    return ans;
}

void updson(int x,int k){
    updata(1,1,n,id[x],id[x]+siz[x]-1,k);
}

void dfs1(int x,int f,int deep){
    dep[x] = deep;
    fa[x] = f;
    siz[x] = 1;
    int maxson=-1;
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)son[x]=y;maxson=siz[y];
    }
}

int cnt=0;
void dfs2(int x,int topf){
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];if(y==fa[x] || y==son[x])continue;
        dfs2(y,y);
    }
}


signed main(){
    int m;cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        add_edge(u,v);add_edge(v,u);
    }

    dfs1(1,0,1);dfs2(1,1);
    build(1,1,n);
    
    for(int i=1;i<=m;++i){
        int op,x,y;cin>>op;
        if(op==1){
            cin>>x>>y;
            updata(1,1,n,id[x],id[x],y);
        }else if(op==2){
            cin>>x>>y;
            updson(x,y);
        }else{
            cin>>x;
            cout<<qrange(1,x)<<endl;
        }
    }

    return 0;
}