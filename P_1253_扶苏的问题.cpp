#include "bits/stdc++.h"
using namespace std;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

#define int long long

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int N = 1e6+10;
const int INF = 1e17+36284637;

int n;
int a[N];
int add[N<<2],mx[N<<2],lz[N<<2],ls[N<<2]={INF};

int readint(){
    int k=0,f=1,c = gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-')f=-1;
    }
    for(;isdigit(c);c = gc()){
        k = k*10 + (c&15);
    }
    return k*f;
}


void pu(int rt){
    add[rt]=add[rt<<1]+add[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}

void pd(int rt,int lenn){
    if(ls[rt]!=INF){
        add[rt<<1]=ls[rt]*(lenn-(lenn>>1));add[rt<<1|1]=ls[rt]*(lenn>>1);
        mx[rt<<1]=ls[rt];mx[rt<<1|1]=ls[rt];
        
        ls[rt<<1]=ls[rt];ls[rt<<1|1]=ls[rt];
        lz[rt<<1]=0;lz[rt<<1|1]=0;
        ls[rt] = INF;
    }
    if(lz[rt]==0)return;
    add[rt<<1]+=lz[rt]*(lenn-(lenn>>1));add[rt<<1|1]+=lz[rt]*(lenn>>1);
    mx[rt<<1]+=lz[rt];mx[rt<<1|1]+=lz[rt];

    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
    lz[rt]=0;
}

void build(int rt,int l,int r){
    ls[rt] = INF;
    if(l==r){
        add[rt]=a[l];
        mx[rt]=a[l];
        return;
    }
    build(lson);build(rson);
    pu(rt);
}

void updata(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){
        add[rt]+=len*k;mx[rt]+=k;
        lz[rt]+=k;
        return;
    }pd(rt,len);
    if(L<=mid)updata(lson,L,R,k);
    if(R>mid)updata(rson,L,R,k);
    pu(rt);
}

void upset(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){
        add[rt] = len*k;mx[rt]=k;
        ls[rt]=k;
        lz[rt] = 0;
        return;
    }pd(rt,len);
    if(L<=mid)upset(lson,L,R,k);
    if(R>mid)upset(rson,L,R,k);
    pu(rt);
}

int querys(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return add[rt];
    }pd(rt,len);
    int ans=0;
    if(L<=mid)ans+=querys(lson,L,R);
    if(R>mid)ans+=querys(rson,L,R);
    return ans;
}

int querym(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return mx[rt];
    }pd(rt,len);
    int ans = -INF;
    if(L<=mid)ans = max(ans,querym(lson,L,R));
    if(R>mid)ans = max(ans,querym(rson,L,R));
    return ans;
}




signed main(){
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        a[i] = readint();
    }

    build(1,1,n);

 

    for(int i=1;i<=q;++i){
        int op=readint(),x=readint(),y=readint(),z;
        if(op==1){
            z=readint();
            upset(1,1,n,x,y,z);
        }else if(op==2){
            z=readint();
            updata(1,1,n,x,y,z);
        }else{
            cout<<querym(1,1,n,x,y)<<'\n';
        }

    }

    return 0;
}