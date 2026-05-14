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

void floydwarshall(vector<vector<int>>& dist,int n){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dist[i][k]<INF && dist[k][j]<INF){
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	}
}


void solve(){
	int n,m;cin>>n>>m;
	vector<int> a(m+1);
	for(int i=1;i<=m;++i){cin>>a[i];}
	vector<vector<int>> g(n+1,vector<int>(n+1));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>g[i][j];
		}
	}

	
	floydwarshall(g,n);
	
	cerr<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cerr<<g[i][j]<<" ";
		}
		cerr<<endl;
	}
	
	i64 sum=0;
	for(int i=1;i<=m-1;++i){
		sum += g[a[i]][a[i+1]];
	}
	cout<<sum<<endl;
	
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
