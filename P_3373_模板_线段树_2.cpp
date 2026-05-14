#include "bits/stdc++.h"
using namespace std;using ll = long long;
#define int long long
int m;


struct node{ll da,lz=0,mul=1;};
void pushUp(vector<node>& tree,int rt){tree[rt].da = (tree[2*rt].da + tree[2*rt+1].da)%m;}


void build(const vector<ll>& data,vector<node>& tree,int rt,int l,int r){
    if(l==r){tree[rt].da = data[l];return;}
    int mid = l+(r-l)/2;
    build(data,tree,2*rt,l,mid);build(data,tree,2*rt+1,mid+1,r);
    pushUp(tree,rt);
}


void pushDown(vector<node>& tree,int rt,int l,int r){
    if(tree[rt].mul!=1){
        int mid = l+(r-l)/2;
        tree[2*rt].da=tree[2*rt].da*tree[rt].mul%m;
        tree[2*rt+1].da=tree[2*rt+1].da*tree[rt].mul%m;

        tree[2*rt].mul*=tree[rt].mul;
        tree[2*rt].mul%=m;
        tree[2*rt+1].mul*=tree[rt].mul;
        tree[2*rt+1].mul%=m;

        tree[2*rt].lz*=tree[rt].mul;
        tree[2*rt].lz%=m;
        tree[2*rt+1].lz*=tree[rt].mul;
        tree[2*rt+1].lz%=m;

        tree[rt].mul=1;
    }
    if(tree[rt].lz!=0){
        int mid = l+(r-l)/2;
        tree[2*rt].da=(tree[2*rt].da+(mid-l+1)*tree[rt].lz)%m;
        tree[2*rt+1].da=(tree[2*rt+1].da+(r-mid)*tree[rt].lz)%m;

        tree[2*rt].lz+=tree[rt].lz;
        tree[2*rt].lz%=m;
        tree[2*rt+1].lz+=tree[rt].lz;
        tree[2*rt+1].lz%=m;

        tree[rt].lz=0;
    }
}


void update(vector<node>& tree,int rt,int l,int r,int L,int R,int val){
//    if(tree[rt].mul!=1)pushDown(tree,rt,l,r);

	if(L<=l&&r<=R){
        tree[rt].da=(tree[rt].da+(r-l+1)*val)%m;
        tree[rt].lz+=val;tree[rt].lz%=m;
        return;
    }pushDown(tree,rt,l,r);

	int mid = l+(r-l)/2;
	if(L<=mid)update(tree,2*rt,l,mid,L,R,val);
    if(R>mid)update(tree,2*rt+1,mid+1,r,L,R,val);
	pushUp(tree,rt);
}


void updateMul(vector<node>& tree,int rt,int l,int r,int L,int R,int val){
//    if(tree[rt].lz!=0)pushDown(tree,rt,l,r);
	if(L<=l&&r<=R){
        tree[rt].da=tree[rt].da*val%m;
        tree[rt].mul*=val;tree[rt].mul%=m;
        tree[rt].lz*=val;tree[rt].lz%=m;
        return;
    }pushDown(tree,rt,l,r);

	int mid = l+(r-l)/2;
	if(L<=mid)updateMul(tree,2*rt,l,mid,L,R,val);
    if(R>mid)updateMul(tree,2*rt+1,mid+1,r,L,R,val);
	pushUp(tree,rt);
}


ll query(vector<node>& tree,int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R){return tree[rt].da%m;}pushDown(tree,rt,l,r);
	ll mid=l+(r-l)/2,ans=0;
	if(L<=mid)ans+=query(tree,2*rt,l,mid,L,R);ans%=m;
	if(R>mid)ans+=query(tree,2*rt+1,mid+1,r,L,R);ans%=m;
	return ans%m;
}



signed main(){
    int n,q;cin>>n>>q>>m;
    vector<ll> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];
    vector<node> tr(8*n+4);build(a,tr,1,1,n);
	int op,x,y,k;
	while(q--){
		cin>>op;
		if(op==2){
			cin>>x>>y>>k;
			update(tr,1,1,n,x,y,k);
		}
		else if(op==1){
            cin>>x>>y>>k;
            updateMul(tr,1,1,n,x,y,k);
        }else{
			cin>>x>>y;
			cout<<query(tr,1,1,n,x,y)<<endl;
		}
	}
    return 0;
}