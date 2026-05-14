#include <bits/stdc++.h>
using namespace std;

#define len (r-l+1)
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

const int N = 1e5+10;
const int INF = 2e9;


int n;
int e,head[N],to[N],nex[N];//链式前向星
int w[N],wi[N],fa[N],son[N],top[N],id[N],dep[N],siz[N];//树的数据
int add[N<<2],mx[N<<2],lz[N<<2];//线段树数据

void add_edge(int u,int v){
    nex[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

//线段树start

void push_up(int rt){
    add[rt]=add[rt<<1]+add[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}

void push_down(int rt,int lenn){
    if(lz[rt]==0)return;
    add[rt<<1]+=lz[rt];add[rt<<1|1]+=lz[rt];
    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];

    push_up(rt);

    lz[rt]=0;
}

void build(int rt,int l,int r){
    if(l==r){
        add[rt] = wi[l];
        mx[rt] = wi[l];
        return;
    }
    push_down(rt,len);
    build(lson);build(rson);
    push_up(rt);
}

void updata(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){
        add[rt]+=len*k;mx[rt]+=k;
        lz[rt]+=k;
        return;
    }
    push_down(rt,len);
    if(L<=mid)updata(lson,L,R,k);
    if(R>mid)updata(rson,L,R,k);
    push_up(rt);
}

int query_sum(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return add[rt];
    }
    push_down(rt,len);
    int ans = 0;
    if(L<=mid)ans+=query_sum(lson,L,R);
    if(R>mid)ans+=query_sum(rson,L,R);
    return ans;
}

int query_max(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return mx[rt];
    }
    push_down(rt,len);
    int ans = -INF;
    if(L<=mid)ans=max(ans,query_max(lson,L,R));
    if(R>mid)ans=max(ans,query_max(rson,L,R));
    return ans;
}

//线段树end

void change(int x,int k){
    int t = query_sum(1,1,n,id[x],id[x]);
    updata(1,1,n,id[x],id[x],k-t);
}

int qmax(int x,int y){
    int ans = -INF;
    while (top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans=max(ans,query_max(1,1,n,id[top[x]],id[x]));
        x=fa[top[x]];
    }
    if(id[x]>id[y])swap(x,y);
    ans=max(ans,query_max(1,1,n,id[x],id[y]));
    return ans;
}

int qsum(int x,int y){
    int ans = 0;
    while (top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=query_sum(1,1,n,id[top[x]],id[x]);
        x=fa[top[x]];
    }
    if(id[x]>id[y])swap(x,y);
    ans+=query_sum(1,1,n,id[x],id[y]);
    return ans;
}

void dfs1(int x,int f,int deep){
    dep[x] = deep;
    fa[x] = f;
    siz[x] = 1;
    int maxson = -1;
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson){
            son[x] = y;maxson=siz[y];
        }
    }
}

int cnt=0;
void dfs2(int x,int topf){
    id[x] = ++cnt;
    wi[cnt] = w[x]; 
    top[x] = topf;
    if(son[x]!=0)dfs2(son[x],topf);
    for(int i=head[x];i;i=nex[i]){
        int y=to[i];if(y==fa[x] || y==son[x])continue;
        dfs2(y,y);
    }
}


int main(){
    cin>>n;
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        add_edge(u,v);add_edge(v,u);
    }
    for(int i=1;i<=n;++i){
        cin>>w[i];
    }

    dfs1(1,0,1);dfs2(1,1);
    build(1,1,n);

    int q;cin>>q;
    for(int i=1;i<=q;++i){
        string op;cin>>op;
        int x,y;cin>>x>>y;
        if(op == "QMAX"){
            cout<<qmax(x,y)<<"\n";
        }else if(op == "QSUM"){
            cout<<qsum(x,y)<<"\n";
        }else{
            change(x,y);
        }
    }
    return 0;
}