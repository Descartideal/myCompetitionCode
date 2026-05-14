#include "bits/stdc++.h"
using namespace std;

int lowbit(int x){
    return x & -x;
}

void change(int pos,int da,int n,vector<int>& re){
    for(;pos<=n;pos+=lowbit(pos)){
        re[pos] += da;
    }
}

int sum_prefix(int pos,vector<int>& re){
    int ans = 0;
    for(;pos;pos-=lowbit(pos)){
        ans+=re[pos];
    }
    return ans;
}

int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    vector<int> d(n+1,0);
    for(int i=1;i<=n;++i){
        d[i] = a[i]-a[i-1];
    }

    vector<int> r(n+1,0);
    for(int i=1;i<=n;++i){
        change(i,d[i],n,r);
    }

    for(int i=1;i<=m;++i){
        int e,x,y,k;cin>>e;
        if(e==1){
            cin>>x>>y>>k;
            change(x,k,n,r);
            if(y>n)continue;
            change(y+1,-k,n,r);
        }else{
            cin>>x;
            cout<<sum_prefix(x,r)<<endl;
        }
    }

    return 0;
}