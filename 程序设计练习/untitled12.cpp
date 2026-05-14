#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<pair<int,int>> a(n+1,{0,0});
	for(int i=1;i<=n;++i){cin>>a[i].first>>a[i].second;}
	
	function<int(int)> dfs;
	dfs = [&](int x){
		int deep=1;
		int y = a[x].first;
		if(y!=0){
			deep = max(deep,dfs(y)+1);
		}
		y = a[x].second;
		if(y!=0){
			deep = max(deep,dfs(y)+1);
		}
		return deep;
	};
	
	cout<<dfs(1)<<endl;
	return 0;
}
