#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+20;
//#define int long long

ll phiSum[N+10];
int pcnt,prime[N+10],phi[N+10];
bool vis[N+10];

void Sieve(int n){
    phi[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            phi[i] = i-1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                phi[x] = p*phi[i];
                break;
            }else{
                phi[x] = (p-1)*phi[i];
            }
        }
    }
}

int mgcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mgcd(b%a,a);
}

int real(int n){
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans+=i*j*mgcd(i,j);
        }
    }
    return ans;
}

int S(int n){
    return n*(n+1)/2;
}

ll my(int n){
    ll ans = 0;
    for(int i=1;i<=n;++i){
        ans+=phi[i]*i*i*S(n/i)*S(n/i);
    }
    return ans;
}

signed main(){
    Sieve(N);
    int n = 10;

    cout<<mgcd(8,12)<<endl;

    for(int i=1;i<=n;++i){
        cout<<my(i)<<" ";
    }cout<<endl;

    for(int i=1;i<=n;++i){
        cout<<real(i)<<" ";
    }cout<<endl;

    for(int i=1;i<=100;++i){
        if(my(i)==real(i)){
            ;
        }else{
            cout<<"NO"<<endl;
        }
    }
    cout<<"OK"<<endl;
}