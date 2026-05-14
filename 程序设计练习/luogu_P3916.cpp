#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n+1);
	vector<int> a(n+1,0);
	for(int i=1;i<=m;++i){
		int x,y;cin>>x>>y;
		g[y].push_back(x);
	}
	
	int mx = 0;
	
	function<void(int)> f;
	f = [&](int q){
		if(a[q]!=0)return;
		a[q] = mx;
		for(auto x:g[q]){
			f(x);
		}
		return;
	};
	
	for(int i=n;i>=1;--i){
		mx = i;
		if(a[i]!=0)continue;
		f(i);
	}
	for(int i=1;i<=n;++i){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
