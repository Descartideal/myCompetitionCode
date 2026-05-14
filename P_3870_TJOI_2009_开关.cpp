#include "bits/stdc++.h"
using namespace std;using ll = long long;

struct node{
    int da=0,lz=0;
};

void pushup(vector<node>& tree,int rt){
    tree[rt].da = tree[2*rt].da + tree[2*rt+1].da;
};

void build(const vector<int>& data,vector<node>& tree,int rt,int l,int r){
    if(l==r){tree[rt].da = data[l];return;}
    int mid = l+(r-l)/2;
    build(data,tree,2*rt,l,mid);build(data,tree,2*rt+1,mid+1,r);
    pushup(tree,rt);
};

void pushdown(vector<node>& tree,int rt,int l,int r){
    if(tree[rt].lz != 0){
        int mid = l+(r-l)/2;
        tree[2*rt].da=(mid-l+1)-tree[2*rt].da;
        tree[2*rt+1].da=(r-mid)-tree[2*rt+1].da;
        tree[2*rt].lz^=1;tree[2*rt+1].lz^=1;
        tree[rt].lz = 0;
    }
}

void update(vector<node>& tree,int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        tree[rt].da=(r-l+1)-tree[rt].da;
        tree[rt].lz^=1;
        return;
    }
    pushdown(tree,rt,l,r);
    int mid = l+(r-l)/2;
    if(L<=mid)update(tree,2*rt,l,mid,L,R);if(R>mid)update(tree,2*rt+1,mid+1,r,L,R);
    pushup(tree,rt);
}

int query(vector<node>& tree,int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){return tree[rt].da;}pushdown(tree,rt,l,r);
    int mid=l+(r-l)/2,ans=0;
    if(L<=mid)ans+=query(tree,2*rt,l,mid,L,R);
    if(R>mid)ans+=query(tree,2*rt+1,mid+1,r,L,R);
    return ans;
}

int main(){
    int n,m;cin>>n>>m;
    vector<node> tr(6*n+4);
    vector<int> a(n+1,0);
    build(a,tr,1,1,n);
    for(int i=0;i<m;++i){
        int op,l,r;cin>>op>>l>>r;
        if(op==0){
            update(tr,1,1,n,l,r);
        }else{
            cout<<query(tr,1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}