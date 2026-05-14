#include <bits/stdc++.h>
using namespace std;
#define int long long

int mgcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mgcd(b%a,a);
}

signed main(){
    int n;cin>>n;
    vector<int> phi;
    for(int i=1;i<=n-1;++i){
        if(mgcd(i,n)==1){
            phi.push_back(i);
        }
    }
    int cnt = phi.size();
    vector<int> w(cnt,1);
    w[0] = phi[0];
    for(int i=1;i<cnt;++i){
        w[i] = w[i-1]*phi[i]%n;
    }

    int j = 0;
    for(int i=cnt-1;i>=0;--i){
        if(w[i]==1){
            j=i;
            break;
        }
    }
    cout<<j+1<<endl;
    for(int i=0;i<=j;++i){
        cout<<phi[i]<<" ";
    }

    return 0;
}