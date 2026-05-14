#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	vector<multiset<int>> g(n+1);
	vector<int> b(n+1,0);
	for(int i=1;i<=m;++i){
		int u,v;cin>>u>>v;
		g[u].insert(v);
	}
	

	
	queue<int> q;
	
	function <void(int)> dfs;
	dfs = [&](int x){
		b[x]=1;
		q.push(x);
		for(auto y:g[x]){
			if(b[y]==1)continue;
			dfs(y);
		}
		return;
	};
	
	dfs(1);
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}cout<<endl;
	
	queue<int> t;
	b = vector<int>(n+1,0);
	queue<int> qq;
	qq.push(1);
	while(!qq.empty()){
		int x = qq.front();
		cerr<<"sdf: "<<x<<endl;
		qq.pop();
		b[x] = 1;
		t.push(x);
		for(auto y:g[x]){
			if(b[y]==1)continue;
			qq.push(y);
			b[y]=1;
		}
	}
	
	while(!t.empty()){
		cout<<t.front()<<" ";
		t.pop();
	}cout<<endl;
	
	
	return 0;
}
