#include "bits/stdc++.h"
using namespace std;

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr

const int N = 200010;
const int INF = 1e9+7;

int MOD;
int n,m,root;

int e,beg[N],nex[N],to[N],w[N],wt[N];
int tr[N*4],lz[N*4],ls[N<<2];
int son[N],id[N],fa[N],dep[N],siz[N],top[N];
int res=0,cnt;

void add_edge(int x,int y){
    to[++e] = y;
    nex[e] = beg[x];
    beg[x] = e;
}

void pu(int rt){
    tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}

void pushdown(int rt,int lenn){
    if(ls[rt]!=INF){
        tr[rt<<1]=ls[rt]*(lenn-(lenn>>1));
        tr[rt<<1|1]=ls[rt]*(lenn>>1);

        ls[rt<<1]=ls[rt];ls[rt<<1|1]=ls[rt];
        lz[rt<<1]=0;lz[rt<<1|1]=0;
        ls[rt] = INF;
    }
    if(lz[rt]==0)return;
    tr[rt<<1]+=lz[rt]*(lenn-(lenn>>1));
    tr[rt<<1|1]+=lz[rt]*(lenn>>1);

    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
    lz[rt]=0;
}

void build(int rt,int l,int r){
    ls[rt] = INF;
    if(l==r){
        tr[rt]=wt[l];
        if(tr[rt]>MOD)tr[rt]%=MOD;
        return;
    }
    build(lson);build(rson);
    tr[rt]=(tr[rt<<1]+tr[rt<<1|1])%MOD;
}

inline void query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R){res+=tr[rt];return;}
    if(ls[rt] != INF || lz[rt])pushdown(rt,len);
    if(L<=mid)query(lson,L,R);
    if(R>mid)query(rson,L,R);
}


inline void update(int rt,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        lz[rt]+=k;
        tr[rt]+=k*len;
        return;
    }
    if(ls[rt] != INF || lz[rt]) pushdown(rt,len);
    if(L<=mid)update(lson,L,R,k);
    if(R>mid)update(rson,L,R,k);
    tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}

inline void upset(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){
        tr[rt] = len*k;
        ls[rt]=k;
        lz[rt] = 0;
        return;
    }pushdown(rt,len);
    if(L<=mid)upset(lson,L,R,k);
    if(R>mid)upset(rson,L,R,k);
    pu(rt);
}



int qRange(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res=0;
		query(1,1,n,id[top[x]],id[x]);
		ans+=res;
		ans%=MOD;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=0;
	query(1,1,n,id[x],id[y]);
	ans+=res;
	return ans%MOD;
}

inline void updRange(int x,int y,int k){
	//k%=MOD;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,1,n,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,1,n,id[x],id[y],k);
}

inline void setRange(int x,int y,int k){
	//k%=MOD;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		upset(1,1,n,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	upset(1,1,n,id[x],id[y],k);
}

int qSon(int x){
	res=0;
	query(1,1,n,id[x],id[x]+siz[x]-1);
	return res;
}

void updSon(int x,int k){
	update(1,1,n,id[x],id[x]+siz[x]-1,k);
}

void setSon(int x,int k){
    upset(1,1,n,id[x],id[x]+siz[x]-1,k);
}

void dfs1(int x,int f,int deep){
	dep[x]=deep; 
	fa[x]=f;
	siz[x]=1;
	int maxson=-1;
	for(int i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];
	}
}

void dfs2(int x,int topf){
	id[x]=++cnt;
	wt[cnt]=w[x];
	top[x]=topf;
	if(!son[x])return;
	dfs2(son[x],topf);
	for(int i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}



int main(){
    root = 1;
    cin>>n;
    MOD = 1e9+7;
    d(n)
    //cin>>n>>m>>root>>MOD;
    //for(int i=1;i<=n;++i)cin>>w[i];
    
    for(int i=1;i<=n-1;++i){
        int a;cin>>a;
        add_edge(a+1,i+1);add_edge(i+1,a+1);
        d(a);
    }
    cin>>m;
    d(m);

    dfs1(root,0,1);dfs2(root,root);
    build(1,1,n);

    while (m--) {
        string op;cin>>op;
        int x;cin>>x;
        x++;
        d(op);
        if(op=="install"){
            int deep = dep[x];cerr<<7;
            int sum = qRange(1,x);
            cout<<deep-sum<<"\n";
            setRange(1,x,1);
        }else{
            int size = siz[x];
            int sum = qSon(x);
            cout<<sum<<"\n";
            setSon(x,0);
        }
    }
    return 0;
}