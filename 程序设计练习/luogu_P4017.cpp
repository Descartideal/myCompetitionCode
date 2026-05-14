#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 80112002;

signed main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n+1);
	vector<int> ru(n+1,0);
	vector<int> a(n+1,0);
	
	for(int i=1;i<=m;++i){
		int x,y;cin>>x>>y;
		ru[y]++;
		g[x].push_back(y);
	}
	
	function<void(int)> dfs;
	dfs = [&](int x){
		if(a[x]!=0)return;
		if(g[x].empty()){
			a[x] = 1;
			return;
		}
		
		int res = 0;
		for(int y:g[x]){
			if(a[y]==0)dfs(y);
			res = (res+a[y])%MOD;
		}
		a[x] = res;
	};
	
	for(int i=1;i<=n;++i){
		if(a[i]==0){
			dfs(i);
		}
	}
	
	int res = 0;
	for(int i=1;i<=n;++i){
		if(ru[i]==0){
			res = (res+a[i])%MOD;
		}
	}
	
	cout<<res<<endl;
	
	cerr<<"asdf"<<endl;
	for(int i=1;i<=n;++i){
		cerr<<a[i]<<endl;
	}
	
	return 0;
}
