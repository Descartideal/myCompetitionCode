#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define len (r-l+1)
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

const int N = 1e5+10;

int n;
ld a[N];
ld add[N<<2],qad[N<<2],lz[N<<2];

void pu(int rt,int l,int r){
    add[rt] = add[rt<<1]+add[rt<<1|1];
    qad[rt] = qad[rt<<1]+qad[rt<<1|1];
}

void pd(int rt,int l,int r){
    if(lz[rt]==0)return;

    qad[rt<<1]+=2.0*lz[rt]*add[rt<<1]+(len-(len>>1))*lz[rt]*lz[rt];
    qad[rt<<1|1]+=2.0*lz[rt]*add[rt<<1|1]+(len>>1)*lz[rt]*lz[rt];

    add[rt<<1]+=lz[rt]*(len-(len>>1));
    add[rt<<1|1]+=lz[rt]*(len>>1);

    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
    lz[rt] = 0;
}

void build(int rt,int l,int r){
    if(l==r){
        add[rt] = a[l];
        qad[rt] = a[l]*a[l];
        return;
    }
    build(lson);build(rson);
    pu(rt,l,r);
}

ld query_add(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return add[rt];
    }pd(rt,l,r);
    ld ans = 0;
    if(L<=mid)ans+=query_add(lson,L,R);
    if(R>mid)ans+=query_add(rson,L,R);
    return ans;
}

ld query_qad(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return qad[rt];
    }pd(rt,l,r);
    ld ans = 0;
    if(L<=mid)ans+=query_qad(lson,L,R);
    if(R>mid)ans+=query_qad(rson,L,R);
    return ans;
}

void updata(int rt,int l,int r,int L,int R,ld k){
    if(L<=l && r<=R){
        qad[rt]+=2.0*k*add[rt]+len*k*k;
        add[rt]+=k*len;
        lz[rt] += k;
        return;
    }pd(rt,l,r);
    if(L<=mid)updata(lson,L,R,k);
    if(R>mid)updata(rson,L,R,k);
    pu(rt,l,r);
}


int main(){
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);

    for(int i=1;i<=q;++i){
        int op,x,y;ld z;cin>>op;
        if(op==1){
            cin>>x>>y>>z;
            updata(1,1,n,x,y,z);
        }else if(op==2){
            cin>>x>>y;
            int m = (y-x+1);
            cout<<fixed<<setprecision(4)<<(query_add(1,1,n,x,y)/m)<<endl;
        }else{
            cin>>x>>y;
            int m = (y-x+1);
            cout<<fixed<<setprecision(4)<<
            (  (query_qad(1,1,n,x,y)/m)  -  ( (query_add(1,1,n,x,y)/m) * (query_add(1,1,n,x,y))/m )  )
            <<endl;
        }
    }

    return 0;
}