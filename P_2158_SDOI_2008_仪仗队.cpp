#include <bits/stdc++.h>
using namespace std;

const int N = 40005;

int pcnt;
int prime[N+10],Mu[N+10],MuSumf[N+10];
bool vis[N+10];

void SieveMu(int n){
    Mu[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            Mu[i] = -1;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            int x = i*p;
            if(x>n)break;
            vis[x] = 1;
            if(i%p==0){
                Mu[x] = 0;
                break;
            }else{
                Mu[x] = -Mu[i];
            }
        }
    }

}

void Init(int n){
    SieveMu(n);
    for(int i=1;i<=n;++i){
        MuSumf[i] = MuSumf[i-1]+Mu[i];
    }
}

signed main(){
    int n;cin>>n;
    if(n==1){
        cout<<0<<"\n";
        return 0;
    }
    n--;
    Init(n+5);

    int ans = 0;
    for(int l=1,r;l<=n;l=r+1){
        int dn = n/l;
        r = n/dn;
        ans += (MuSumf[r]-MuSumf[l-1])*dn*dn;
    }

    cout<<ans+2<<"\n";
}