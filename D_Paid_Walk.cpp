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
	int n,m,L,S,T;cin>>n>>m>>L>>S>>T;
	vector<vector<pii>> g(n+1);
	for(int i=0;i<m;++i){
		int u,v,c;cin>>u>>v>>c;
		g[u].push_back({v,c});
	}
	
	queue<tuple<int,int,int>> q;
	q.push({1,0,0});
	
	unordered_map<int,int> ans;
	
	while (!q.empty()) {
		auto [x,l,c] = q.front();q.pop();
		if(l==L){
			if(S<=c && c<=T){
				++ans[x];
			}
			continue;
		}
		
		for(auto [y,cc]:g[x]){
			q.push({y,l+1,c+cc});
		}
	}
	
	for(int i=1;i<=n;++i){
		if(ans[i]!=0){
			cout<<i<<" ";
		}
	}cout<<endl;
	
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	solve();
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
