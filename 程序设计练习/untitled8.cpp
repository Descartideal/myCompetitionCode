#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const i64 MOD = 1e9+7;

vector<i64> a(51,0),b(51,0),c(51,0),d(51,0);


void solve(){
	i64 n,k;cin>>n>>k;
	vector<i64> in(n);
	for(i64& x:in){cin>>x;};
	sort(in.begin(),in.end());
	
	i64 score = 1;
	
	function<void(int)> f;
	f = [&](int y){
		if(k<=0)return;
		
		auto it = lower_bound(a.begin(),a.end(),k);
		int index = it - a.begin();
		
		cerr<<"index: "<<index<<" K: "<<k<<endl;
		
		if(k==a[index-1]+1){
			score = score*d[index]%MOD;
			return;
		}else{
			score = score*d[index]%MOD;
			k-=c[index];
			f(index-1);
			return;
		}
	};
	
	for(int i=0;i<n;++i){
		i64 x = in[i];
		
		if(k<=0)break;
		
		if(x>50){
			--k;
			score = score*x%MOD;
			f(x-1);
			break;
		}
		
		if(k<=c[x]){
			--k;
			score = score*x%MOD;
			f(x-1);
			break;
		}else{
			k-=c[x];
			score = score*d[x]%MOD;
		}
	}
	
	cerr<<"anwser: ";
	cout<<score<<endl;
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	
	a[1]=1;b[1]=1;c[1]=1;d[1]=1;
	
	for(int i=2;i<=50;++i){
		a[i] = 2*a[i-1] + 1;
		c[i] = 2*c[i-1];
		
		b[i] = (b[i-1]*b[i-1]%MOD)*i%MOD;
		d[i] = i*b[i-1]%MOD;
		
		//cerr<<"ubf: "<<i<<": asdf: "<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
	}
	
	
	
	
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
