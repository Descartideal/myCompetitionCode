#include <bits/stdc++.h>
using namespace std;

#define len (r-l+1)
#define mid ((r+l)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

const int N = 1e5+10;

int n,a[N];
int mi[N<<2];

void pu(int rt,int l,int r){
    mi[rt] = min(mi[rt<<1],mi[rt<<1|1]);
}

void build(int rt,int l,int r){
    if(l==r){
        mi[rt] = a[l];
        return;
    }
    build(lson);build(rson);
    pu(rt,l,r);
}

int query(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return mi[rt];
    }
    int ans = INT_MAX;
    if(L<=mid)ans = min(ans,query(lson,L,R));
    if(R>mid)ans = min(ans,query(rson,L,R));
    return ans;
}



int main(){
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;++i){
        int x,y;cin>>x>>y;
        cout<<query(1,1,n,x,y)<<" ";
    }

    return 0;
}