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

const int MOD = 998244353;

int mp(int x,int y){
	//cerr<<"MP  "<<x<<" "<<y<<endl;
	
	int res = 1;
	while(y>0){
		if(y&1){
			res = (res*x)%MOD;
		}
		y/=2;
		x = x*x%MOD;
	}
	
	//cerr<<"res: "<<res<<endl;
	return res;
}

int inv(int x){
	return mp(x,MOD-2);
}

int p[100];

void solve(){
	int n;cin>>n;
	vector<int> a(n+1);for(int& x:a)cin>>x;
	
	int high,low,sum;
	sum = accumulate(a.begin(),a.end(),0);
	low = sum/n;high = low+1;
	
	int gh_n=sum-low*n,gl_n=n-gh_n;
	
	int l_n = 0,h_n = 0;
	for(int i=1;i<=n;++i){
		if(a[i]>high){
			cout<<0<<endl;
			return;
		}
		if(a[i]==low){
			++l_n;
		}
		if(a[i]==high){
			++h_n;
		}
	}
	if(h_n>gh_n){
		cout<<0<<endl;
		return;
	}
	
	int factor = p[gh_n]*p[gl_n]%MOD;
	int res = p[n-h_n]*inv(p[gh_n-h_n]*p[gl_n]%MOD)%MOD;
	res = res*factor%MOD;
	
	cout<<res<<endl;
	return;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	
	p[1]=1;p[0]=1;
	for(int i=2;i<100;++i){
		p[i] = p[i-1]*i%MOD;
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
