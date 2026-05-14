#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n,m;cin>>n>>m;
	vector<vector<pair<int,int>>> g(n+1);
	vector<int> a(n+1,-99999999);
	vector<int> b(n+1,0);
	
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		g[v].push_back({u,w});
	}

	a[1]=0;
	for(int i=2;i<=n;++i){
		for(auto [u,w]:g[i]){
			if(a[u]==-1)continue;
			if(a[u]+w>a[i]){
				a[i] = a[u]+w;
			}
		}
	}
	
	if(a[n]==-99999999){
		cout<<-1<<endl;
		return 0;
	}
	cout<<a[n]<<endl;
	return 0;
}
