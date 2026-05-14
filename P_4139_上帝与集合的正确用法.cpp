#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e7+10;
int phi[N+10];
vector<bool> vis(N+10,0);
vector<int> prime;

inline int mmul(int a,int b,int M){
    return a*b%M;
}

inline int mpow(int a,int b,int M){
    int res=1;a%=M;
    while(b){
        if(b&1){
            res=mmul(res,a,M);
        }
        a=mmul(a,a,M);
        b>>=1;
    }
    return res;
}

inline void Initphi(){
    phi[1] = 1;
    for(int i=2;i<=N;++i){
        if(!vis[i]){
            prime.push_back(i);
            phi[i] = i-1;
        }
        for(int p:prime){
            int t = i*p;
            if(t>N)break;
            vis[t] = 1;
            if(i%p==0){
                phi[t] = phi[i]*p;
                break;
            }else{
                phi[t] = phi[i]*(p-1);
            }
        }
    }
}

inline int god(int M){
    if(M==1)return 0;
    return mpow(2,god(phi[M])+phi[M],M);
}

inline void solve(){
    int n;cin>>n;
    cout<<god(n)<<endl;
    return;
}

signed main(){
    Initphi();
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}