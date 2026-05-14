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

    vector<int> r(n+1,0);
    for(int i=1;i<=n;++i){
        change(i,a[i],n,r);
    }

    for(int i=1;i<=m;++i){
        int e,x,y;cin>>e>>x>>y;
        if(e==1){
            change(x,y,n,r);
        }else{
            cout<<sum_prefix(y,r)-sum_prefix(x-1,r)<<endl;
        }
    }

    return 0;
}