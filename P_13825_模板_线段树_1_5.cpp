#include <bits/stdc++.h>
using namespace std;

#define mid ((l+r)>>1)
#define len (r-l+1)
#define lson rt<<1,l,mid
#define rson ((rt<<1)+1),mid+1,r

const int N = 2e5+10;
int add[N<<2],lz[N<<2];
int n;
vector<int> a;

int le(int l,int r){
    return a[r]-a[l]+1;
}

void pu(int rt,int l,int r){
    if(r-l==2){

    }
    if(r-l==3){
        
    }
    add[rt]=add[rt<<1]+add[rt<<1|1];
}

void pd(int rt,int lenn){
    if(lz[rt]==0)return;
    add[rt<<1]+=lz[rt];add[rt<<1|1]+=lz[rt];
    lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
    lz[rt] = 0;
}

void build(int rt,int l,int r){
    if(l==r){
        add[rt]=0;
        return;
    }pd(rt,len);
    build(lson);build(rson);
    add[rt]=add[rt<<1]+add[rt<<1|1];
}

void updata(int rt,int l,int r,int L,int R,int k){
    if(L<=l && r<=R){
        add[rt] += k*len;lz[rt]+=k;
        return;
    }pd(rt,len);
    if(L<=mid)updata(lson,L,R,k);
    if(R>mid)updata(rson,L,R,k);
    add[rt]=add[rt<<1]+add[rt<<1|1];
}

int query(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return add[rt];
    }pd(rt,len);
    int ans = 0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}

int f(int x){
    return lower_bound(a.begin(),a.end(),x)-a.begin()+1;
}




int main(){
    int mx,m;cin>>mx>>m;

    a.push_back(0);
    vector<vector<int>> b(m+1,vector<int>(4));
    for(int i=1;i<=m;++i){
        cin>>b[i][0];
        if(b[i][0]==1){
            cin>>b[i][1]>>b[i][2]>>b[i][3];
        }else{
            cin>>b[i][1]>>b[i][2];
        }
        a.push_back(b[i][1]);a.push_back(b[i][2]);
    }

    sort(a.begin()+1,a.end());
    a.erase(unique(a.begin()+1,a.end()),a.end());
    n = a.size()-1;
    

    build(1,1,n);


    for(int i=1;i<=m;++i){
        int op = b[i][0],x,y,z;
        if(op==1){
            x=b[i][1],y=b[i][2],z=b[i][3];
            updata(1,1,n,f(x),f(y),z);
        }else{
            x=b[i][1],y=b[i][2];
            cout<<query(1,1,n,f(x),f(y))<<'\n';
        }
    }




    return 0;
}