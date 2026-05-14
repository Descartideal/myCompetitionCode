#include "bits/stdc++.h"
using namespace std;using ll = long long;
#define int long long

struct node{ll da,lz=0;};
void pushUp(vector<node>& tree,int rt){tree[rt].da = tree[2*rt].da + tree[2*rt+1].da;}
void build(const vector<ll>& data,vector<node>& tree,int rt,int l,int r){
    if(l==r){tree[rt].da = data[l];return;}
    int mid = l+(r-l)/2;
    build(data,tree,2*rt,l,mid);build(data,tree,2*rt+1,mid+1,r);
    pushUp(tree,rt);
}
void pushDown(vector<node>& tree,int rt,int l,int r){
    if(tree[rt].lz!=0){
        int mid = l+(r-l)/2;
        tree[2*rt].da+=(mid-l+1)*tree[rt].lz;tree[2*rt+1].da+=(r-mid)*tree[rt].lz;
        tree[2*rt].lz+=tree[rt].lz;tree[2*rt+1].lz+=tree[rt].lz;
        tree[rt].lz=0;
    }
}
void update(vector<node>& tree,int rt,int l,int r,int L,int R,int val){
	if(L<=l&&r<=R){tree[rt].da+=(r-l+1)*val;tree[rt].lz+=val;return;}pushDown(tree,rt,l,r);
	int mid = l+(r-l)/2;
	if(L<=mid)update(tree,2*rt,l,mid,L,R,val);if(R>mid) update(tree,2*rt+1,mid+1,r,L,R,val);
	pushUp(tree,rt);
}
ll query(vector<node>& tree,int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R){return tree[rt].da;}pushDown(tree,rt,l,r);
	ll mid=l+(r-l)/2,ans=0;
	if(L<=mid)ans+=query(tree,2*rt,l,mid,L,R);
	if(R>mid)ans+=query(tree,2*rt+1,mid+1,r,L,R);
	return ans;
}

signed main(){
    int n,m;cin>>n>>m;
    vector<ll> a(n+1);for(int i=1;i<=n;i++) cin>>a[i];
    vector<node> tr(4*n+4);build(a,tr,1,1,n);
	int op,x,y,k;
	while(m--){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update(tr,1,1,n,x,y,k);
		}
		else{
			cin>>x>>y;
			cout<<query(tr,1,1,n,x,y)<<endl;
		}
	}
    return 0;
}