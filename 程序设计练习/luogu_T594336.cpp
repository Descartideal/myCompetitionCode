#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int INF = INT_MAX;

int dijkstra(vector<vector<tuple<int,int,int>>> g,int n,int s,int t){
	vector<pair<int,int>> dist(n+1,{INF,INF});dist[s]={0,0};
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
	pq.push({0,0,s});
	
	while(!pq.empty()){
		auto [h,w,u] = pq.top();
		pq.pop();
		
		if(u == t){
			return dist[u].second;
		}
		
		for(auto [nv,nh,nw]:g[u]){
			int dh=dist[nv].first;
			int dw=dist[nv].second;
			pii next = {h+nh,w+nw};
			pii last = {dh,dw}; 
			if(next<last){
				dist[nv] = next;
				pq.push({h+nh,w+nw,nv});
			}
		}
	}
	return -1;
}

void solve(){
	int n,m,k,s,t;cin>>n>>m>>k>>s>>t;
	vector<vector<tuple<int,int,int>>> g(n+1,vector<tuple<int,int,int>>(n+1,{0,0,0}));
	unordered_set<int> K;
	for(int i=1;i<=k;++i){
		int x;cin>>x;
		K.insert(x);
	}
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		auto it = K.find(v);
		if(it == K.end()){
			g[u].push_back({v,0,w});
		}else{
			g[u].push_back({v,1,w});
		}
		cerr<<"asdf\n";
	}
	
	cerr<<"start\n";
	
	cout<<dijkstra(g,n,s,t)<<endl;
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
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
