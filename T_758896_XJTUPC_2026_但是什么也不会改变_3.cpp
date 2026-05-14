#include <bits/stdc++.h>
using namespace std;
#define int long long

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr

const int M = 998244353;
const int N = 1e6+7;

int a[N+10];
int power[N+10];

int mpow(int a,int b){
    cerr<<7<<endl;
    int res = 1;
    while(b){
        if(b&1){
            res *= a;
            res %= M;
        }
        a = a*a;a %= M;
        b>>=1;
    }
    return res;
}

int inv(int x){
    return mpow(x,M-2);
}

int C(int n,int m){
    int res = power[n];

    res *= inv( 1LL*power[n-m]*power[m]%M );
    res %= M;

    return res;
}

void solve(){
    int n;cin>>n;
    //cerr<<mpow(3,4)<<endl;
    //cerr<<inv(2)<<endl;
    cerr<<6677<<endl;
    d(n)
    int res = a[n];
    d(res)
    res = res-C(n,0)-C(n,1)-C(n,2);

    res *= 2;
    res = (res%M+M)%M;
    cout<<res<<endl;
}

signed main(){
    a[0]=1;
    for(int i=1;i<=N;++i){
        a[i] = 2*a[i-1];
        a[i] %= M;
        //cerr<<a[i]<<endl;
    }
    power[0] = 1;
    for(int i=1;i<=N;++i){
        power[i] = i*power[i-1];
        power[i] %= M;
        //cerr<<power[i]<<endl;
    }
    solve();
}