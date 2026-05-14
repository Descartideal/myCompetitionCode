#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int INF = 1e9;

void floydwarshall(vector<vector<int>>& dist,int n){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dist[i][k]<INF || dist[k][j]<INF){
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	}
}

void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
	for(int i=1;i<=n;++i){
		dist[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;
		dist[u][v] = w;
		dist[v][u] = w;
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cerr<<dist[i][j]<<" ";
		}
		cerr<<endl;
	}
	
	
	floydwarshall(dist,n);
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cerr<<dist[i][j]<<" ";
		}
		cerr<<endl;
	}
	
	
	i64 mi = INT64_MAX;
	cerr<<"mi:"<<mi<<endl;
	for(int a=1;a<=n-1;++a){
		for(int b=a+1;b<=n;++b){
			i64 sum = 0;
			for(int i=1;i<=n-1;++i){
				for(int j=i+1;j<=n;++j){
					sum += min(dist[i][j],min(dist[i][a]+dist[b][j],dist[i][b]+dist[a][j]));	
				}
			}
			mi = min(mi,sum);
		}
	}
	cout<<mi<<endl;
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
