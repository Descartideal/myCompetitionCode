#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 35;
ll f[N][N];
int rt[N][N];
int d[N];
int n;

void preorder(int l,int r){
    if(l>r)return;
    int k=rt[l][r];
    cout<<k<<" ";
    preorder(l,k-1);
    preorder(k+1,r);
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>d[i];
    }
    for(int i=1;i<=n;++i){
        f[i][i] = d[i];
        rt[i][i] = i;
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;
            f[l][r] = 0;

            for(int k=l;k<=r;++k){
                ll left = (k==l?1:f[l][k-1]);
                ll right = (k==r?1:f[k+1][r]);
                ll val = left*right+d[k];

                if(val > f[l][r]){
                    f[l][r] = val;
                    rt[l][r] = k;
                }
            }
        }
    }
    cout<<f[1][n]<<'\n';
    preorder(1,n);

    return 0;
}