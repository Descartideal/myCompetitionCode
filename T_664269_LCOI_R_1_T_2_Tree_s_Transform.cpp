#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

#define int long long

const int N = 2e7+100;
const int M = 998244353;

int v[N+1];

int pm(int x,int y){
    int ans = 1;
    while(y>0){
        if(y&1){
            ans*=x;
            ans%=M;
        }
        x=x*x;x%=M;
        y>>=1;
    }
    return ans;
}

int inv(int x){
    return pm(x,M-2)%M;
}


void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<1<<endl;
        return;
    }
    if(n==3){
        cout<<2<<endl;
        return;
    }

    int k=n-3;
    int res = 1;
    res*=v[2*k];res%=M;
    res*=inv(v[k]);res%=M;
    res*=(n-1);res%=M;
    cout<<res<<endl;

	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);

    v[0] = 1;
    for(int i=1;i<=N;++i){
        v[i] = v[i-1]*i%M;
    }

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
