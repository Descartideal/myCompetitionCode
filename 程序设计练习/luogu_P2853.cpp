#include<bits/stdc++.h>
using namespace std;

int main(){
	int k,n,m;cin>>k>>n>>m;
	vector<int> cow(k+1);
	vector<int> a(n+1,0);
	vector<vector<int>> g(n+1);
	for(int i=1;i<=k;++i){
		cin>>cow[i];
	}
	for(int i=1;i<=m;++i){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	
	vector<int> b;
	function <void(int)> dfs;
	dfs = [&](int u){
		b[u]=1;
		a[u]++;
		for(auto v:g[u]){
			if(b[v]==1)continue;
			dfs(v);
		}
	};
	
	for(int i=1;i<=k;++i){
		int x = cow[i];
		b = vector<int>(n+1,0);
		dfs(x);
	}
	
	int res = 0;
	for(int i=1;i<=n;++i){
		if(a[i]==k)res++;
	}
	
	cout<<res<<endl;
	
	return 0;
}
