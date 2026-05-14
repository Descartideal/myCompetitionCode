#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

#define len (r-l+1)
#define mid ((l+r)>>1)
#define lson (rt<<1),l,mid
#define rson (rt<<1|1),(mid+1),r

const int N = 5e5+20;

int n;

int a[N];
int add[N<<2],mx[N<<2],lmx[N<<2],rmx[N<<2],lz[N<<2];


void pu(int rt,int l,int r){
    add[rt] = add[rt<<1]+add[rt<<1|1];
    mx[rt] = max({mx[rt<<1],mx[rt<<1|1],rmx[rt<<1]+lmx[rt<<1|1]});
    lmx[rt] = max({lmx[rt<<1],add[rt<<1]+lmx[rt<<1|1]});
    rmx[rt] = max({rmx[rt<<1|1],add[rt<<1|1]+rmx[rt<<1]});
}

void build(int rt,int l,int r){
    if(l==r){
        add[rt] = a[l];
        mx[rt] = a[l];
        lmx[rt] = a[l];
        rmx[rt] = a[l];
        return;
    }
    build(lson);build(rson);
    pu(rt,l,r);
}

array<int,4> query(int rt,int l,int r,int L,int R){
    if(L<=l && r<=R){
        return {add[rt],mx[rt],lmx[rt],rmx[rt]};
    }

    array<int,4> ans;
    if(L<=mid && R>mid){
        array<int,4> ans1 = query(lson,L,R);
        array<int,4> ans2 = query(rson,L,R);
        ans[0] = ans1[0]+ans2[0];
        ans[1] = max({ans1[1],ans2[1],ans1[3]+ans2[2]});
        ans[2] = max(ans1[2],ans1[0]+ans2[2]);
        ans[3] = max(ans2[3],ans2[0]+ans1[3]);
    }else if(L<=mid){
        ans = query(lson,L,R);
    }else{
        ans = query(rson,L,R);
    }
    return ans;
}

void updata(int rt,int l,int r,int x,int k){
    if(l==x && r==x){
        add[rt] = k;
        mx[rt] = k;
        lmx[rt] = k;
        rmx[rt] = k;
        return;
    }
    if(x<=mid)updata(lson,x,k);if(x>mid)updata(rson,x,k);
    pu(rt,l,r);
}
/** 

int main(){
    int q;cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;++i){
        int op,x,y;cin>>op>>x>>y;
        if(op==2){
            updata(1,1,n,x,y);
        }else{
            if(x>y)swap(x,y);
            cout<<query(1,1,n,x,y)[1]<<endl;
        }
    }

    return 0;
}

*/



struct mxx{
    vector<int> lg;
    vector<vector<int>> f;

    mxx(int n,const vector<int>& a){
        lg.resize(n+1,0);
        f.resize(n+1,vector<int>(20,0));

        lg[1]=0;
        for (int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
        for (int i=1;i<=n;i++)f[i][0]=a[i];
        for (int j=1;j<=lg[n];j++)
        for (int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }

    int Q(int x,int y){
        int l = lg[y-x+1];
        return max(f[x][l],f[y-(1<<l)+1][l]);
    }
};

struct mi{
    vector<int> lg;
    vector<vector<int>> f;
    //int lg[10010],f[10010][20];

    mi(int n,const vector<int>& a){
        lg.resize(n+1,0);
        f.resize(n+1,vector<int>(20,0));

        lg[1]=0;
        for (int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
        for (int i=1;i<=n;i++)f[i][0]=a[i];
        for (int j=1;j<=lg[n];j++)
        for (int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }

    int Q(int x,int y){
        int l = lg[y-x+1];
        return min(f[x][l],f[y-(1<<l)+1][l]);
    }
};

signed main(){
    int k;cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    
    build(1,1,n);
    vector<int> pos(n+1,0);
    
    vector<int> aa(n+1,0);
    for(int i=1;i<=n;++i){
        aa[i] = a[i];
    }
    
    mi mi(n,aa);
    mxx mxx(n,aa);


    int j = 1;
    for(int i=1;i<=n;++i){
        while(mxx.Q(j,i)-mi.Q(j,i) > k){
            j++;
        }
        pos[i] = j;
    }

    //cerr<<pos<<endl;

    int ans = 0;
    for(int i=1;i<=n;++i){
        ans = max(ans,query(1,1,n,pos[i],i)[1]);
    }
    cout<<ans<<endl;

    return 0;
}