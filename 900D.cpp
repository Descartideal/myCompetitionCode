#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9+7;
#define int long long

ll mpow(int a,int b){
    ll res = 1;
    while(b){
        if(b&1){
            res*=a;res%=M;
        }
        a = a*a;
        a%=M;
        b>>=1;
    }
    return res;
}

signed main(){
    ll x,y;cin>>x>>y;
    if(y%x==0){
        ll t = y/x-1;
        cout<<mpow(2,t)-1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}