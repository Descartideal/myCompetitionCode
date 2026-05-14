#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const ll P=1000000007LL;

ll pw(ll a,ll e){
    ll r=1%P;
    a%=P;
    while(e){
        if(e&1)r=r*a%P;
        a=a*a%P;
        e>>=1;
    }
    return r;
}

void solve(){
    int n;
    ll m;
    cin>>n>>m;
    vector<int>c(n+1);
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        ++c[x];
    }
    ll g=0;
    for(int s=1;s<=n;++s){
        if(!c[s])continue;
        if(c[s]%s){
            cout<<0<<"\n";
            return;
        }
        g+=c[s]/s;
    }
    if(g>m){
        cout<<0<<"\n";
        return;
    }
    static vector<ll>f,ivf;
    static int ok=0;
    if(!ok){
        int N=200000;
        f.assign(N+1,1);
        ivf.assign(N+1,1);
        for(int i=1;i<=N;++i)f[i]=f[i-1]*i%P;
        ivf[N]=pw(f[N],P-2);
        for(int i=N;i>=1;--i)ivf[i-1]=ivf[i]*i%P;
        ok=1;
    }
    ll ans=1;
    for(int s=1;s<=n;++s){
        int k=c[s];
        if(!k)continue;
        ll t=k/s;
        ll cur=f[k];
        ll isf=pw(f[s],P-2);
        cur=cur*pw(isf,t)%P;
        cur=cur*ivf[t]%P;
        ans=ans*cur%P;
    }
    ll fall=1;
    for(ll i=0;i<g;++i){
        ll x=(m-i)%P;
        if(x<0)x+=P;
        fall=fall*x%P;
    }
    cout<<ans*fall%P<<"\n";
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}


















/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//————自由是遗忘的左伴随
