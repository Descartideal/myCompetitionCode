#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5+10;
int pcnt,prime[N+10];
bool vis[N+10];

void Sieve(int n){
    vis[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            ll x = p*i;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                break;
            }
        }
    }
}

bool isPrime(int x){
    if(x==1)return false;
    return !vis[x];
}

int id(int x){
    if(x==1)return 1;
    if(x&1)return 3;
    return 2;
}

signed main(){
    Sieve(N);
    int n;cin>>n;
    vector<int> a(n+1);for(int i=1;i<=n;++i)cin>>a[i];
    vector<int> b(n+1);for(int i=2;i<=n;++i)b[i] = a[i-1]+a[i];
    vector<vector<int>> dp(n+1,vector<int>(4,-1));

    dp[0] = {0,1,1,1};



    for(int i=2;i<=n;++i){
        if(isPrime(b[i])){
            if( id(a[i-1])==1 ){
                dp[i][0] = dp[i-1][0];
            }
            
        }else{

        }
    }
}