//teamname: The Farce is Over
//Acmer: Descartideal

#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;
using ll = long long;

#define int i128

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr

const int MOD = 20101009;

const int N = 1e7+1000;
bool vis[N+10];
int prime[N+10],preh[N+10],h[N+10],hSumf[N+10];
//int Mu[N+10],kMu[N+10],kMuSumf[N+10];
int pcnt;


void SieveMu(int n) {
    //Mu[1] = 1;
    preh[1] = 1;
    for (int i=2;i<=n;++i) {
        if (!vis[i]) {
            prime[++pcnt] = i;
            //Mu[i] = -1;
            preh[i] = 1LL-i;
        }
        for (int j=1;j<=pcnt;++j) {
            int p = prime[j];
            int x = i*p;
            if (x>n)break;
            vis[x] = 1;
            if (i%p==0) {
                //Mu[x] = 0;
                preh[x] = preh[i];
                break;
            }else {
                //Mu[x] = -Mu[i];
                preh[x] = preh[i]*(1-p);
                preh[x]%=MOD;
            }
        }
    }
}

void Init(int n) {
    SieveMu(n);

    /** 
    for (int i=1;i<=n;++i) {
        kMu[i] = i*Mu[i];
    }
    for (int i=1;i<=n;++i) {
        kMuSumf[i] = kMuSumf[i-1]+kMu[i];
        kMuSumf[i] %= MOD;
    }
    */

    for(int i=1;i<=n;++i){
        h[i] = i*preh[i];
        h[i] %= MOD;
    }

    for (int i=1;i<=n;++i) {
        hSumf[i] = hSumf[i-1]+h[i];
        hSumf[i] %= MOD;
    }
}

int S(int x) {
    return (x*(x+1)/2)%MOD;
}

signed main(){
    ll _n,_m;
    int n,m;cin>>_n>>_m;
    n = _n;m = _m;
    if (n>m)swap(n,m);
    Init(N+1);
/** 
    for(int i=1;i<=10;++i){
        cerr<<preh[i]<<" ";
    }cerr<<endl;

    cerr<<hSumf[0]<<endl<<endl;
    for (int i=1;i<=20;++i) {
        cerr<<hSumf[i]<<" ";
    }cerr<<endl<<endl;
    for (int i=1;i<=20;++i) {
        cerr<<h[i]<<" ";
    }cerr<<endl<<endl;
*/
    int limit = n;
    int ans = 0;
    for (int l=1,r;l<=limit;l=r+1) {
        int dn = n/l;
        int dm = m/l;
        r = min(n/dn,m/dm);

        //d( hSumf[r]-hSumf[l-1] )
        //d( dn );
        //d( dm );

        ans += (hSumf[r]-hSumf[l-1])*S(dn)*S(dm);
        //d(ans);
        ans %= MOD;
    }

    ans = (ans%MOD+MOD)%MOD;
    ll _ans = ans;
    cout<<_ans<<endl;
}

