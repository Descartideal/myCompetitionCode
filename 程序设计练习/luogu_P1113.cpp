#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main(){
	int n;cin>>n;
	vector<int> t(n+1);
	vector<vector<int>> g(n+1);
	vector<i64> a(n+1,0);
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		cin>>t[i];
		
		cin>>x;
		while(x!=0){
			g[x].push_back(i);
			cin>>x;
		}
	}
	
	function<void(int)> dfs;
	dfs = [&](int x){
		if(g[x].empty()){
			a[x] = t[x];
		}
		i64 mx = 0;
		for(int y:g[x]){
			if(a[y]==0){
				dfs(y);	
			}
			mx = max(mx,a[y]);
		}
		a[x] = mx + t[x];
	};
	
	i64 mx = LONG_LONG_MIN;
	for(int i=1;i<=n;++i){
		if(a[i]!=0)continue;
		dfs(i);
		mx = max(mx,a[i]);
	}
	
	cout<<mx<<endl;
	
	return 0;
}
