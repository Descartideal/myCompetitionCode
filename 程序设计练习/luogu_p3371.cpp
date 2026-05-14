#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


const int N = 100010;
const int INF = INT32_MAX;

vector<pair<int,int>> graph[N];
int dist[N];
bool visited[N];

void dijkstra(int start){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	fill(dist,dist+N,INF);
	dist[start] = 0;
	pq.push({0,start});
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		if(visited[u])continue;
		visited[u] = true;
		for(auto& edge:graph[u]){
			int v=edge.first,w=edge.second;
			if(dist[u]+w<dist[v]){
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}

void solve(){
	int n,m,s;cin>>n>>m>>s;
	
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		graph[u].push_back({v,w});
	}
	dijkstra(s);
	for(int i=1;i<=n;++i){
		if(i-1)cout<<" ";
		cout<<dist[i];
	}
	return;
}


signed main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
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
