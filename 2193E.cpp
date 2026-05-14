#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


const int INF=1e9;

void solve(){
	int n;cin>>n;
	vector<int> cnt(n+1);
	for(int i=0;i<n;i++){int x;cin>>x;cnt[x]++;}
	vector<int> dist(n+1,INF);
	queue<int> q;
	for(int v=1;v<=n;v++) if(cnt[v]){dist[v]=1;q.push(v);}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int k=1;k*x<=n;k++){
			if(!cnt[k]) continue;
			int y=x*k;
			if(dist[y]==INF){
				dist[y]=dist[x]+1;
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i]==INF) cout<<-1;
		else cout<<dist[i];
		cout<<(i==n?'\n':' ');
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	int t;cin>>t;
	while(t-->0){
		solve();
	}
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
