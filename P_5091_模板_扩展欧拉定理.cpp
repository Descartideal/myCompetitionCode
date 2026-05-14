#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int mpow(int a,int b,int m){
    int res=1;a%=m;
    while(b){
        if(b&1){
            res*=a;res%=m;
        }
        a=a*a;a%=m;
        b>>=1;
    }
    return res;
}


inline int phi(int n){
    int res = n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0)res=res/i*(i-1);
        while(n%i==0)n/=i;
    }
    if(n>1)res=res/n*(n-1);
    return res;
}

signed main(){
    int a,m;cin>>a>>m;
    string b;cin>>b;

    int x=0;
    int M = phi(m);
    for(int i=0;i<b.size();++i){
        int t = b[i]-'0';
        x=x*10+t;if(b.size()>5)x%=M;
    }
    if(x>M){
        cout<<mpow(a,x+M,m)<<endl;
    }else{
        cout<<mpow(a,x,m)<<endl;
    }
    
    return 0;
}