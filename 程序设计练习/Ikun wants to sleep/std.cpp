#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	i64 n,m,k;cin>>n>>m>>k;
	i64 L=k-1,R=n-k;
	auto f = [&](i64 a){
		a = min(a,m);
		a = max(0LL,a);
		i64 t1 = min(L,(a+1)/2)+min(min((a+2)/2,m-a),R)+1LL;
		i64 t2 = 0;
		t2 = min(R,(a+1)/2)+min(min((a+2)/2,m-a),L)+1LL;
		
		return max(t1,t2);
	};
	
	/**
	  
	  i64 l,r,mid;
	  l=0;r=m;mid=(l+r)/2;
	  while(1){
	  
	  }
	  
	 **/
	
	vector<i64> may;
	for(int i=0;i<=min(2*n,m);++i){
		may.push_back(f(i));
	}
	
	
	
	i64 mx = 1;
	//cerr<<"asdf: ";
	int ii=0;
	
	for(int i=0;i<may.size();++i){
		if(mx<may[i]){
			mx = may[i];
			ii = i;
		}
		
		
		//	cerr<<may[i]<<" ";
	}
	//cerr<<endl;
	cout<<mx<<endl;
	
	//cerr<<ii<<endl;
	
	return;
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
