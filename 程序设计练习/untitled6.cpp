#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve1(){
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n+1);
	for(int i=1;i<=m;++i){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	queue<int> q;
	vector<int> dist(n+1,-1);
	q.push(1);dist[1] = 0;
	while(!q.empty()){
		int x = q.front();q.pop();
		int d = dist[x];
		for(int y:g[x]){
			if(dist[y]!=-1)continue;
			q.push(y);
			dist[y]=d+1;
		}
	}
	
	for(int i=1;i<=n;++i){
		int t = (dist[i]%6)/2;
		if(t==0){
			cout<<'r';
		}else if(t==1){
			cout<<'g';
		}else{
			cout<<'b';
		}
	}
	cout<<endl;
	return;
}


void solve3(){
	int n;cin>>n;
	string s;cin>>s;
	int r=0,g=0,b=0;
	for(int i=0;i<n;++i){
		char c = s[i];
		if(c=='r'){
			++r;
		}else if(c=='g'){
			++g;
		}else{
			++b;
		}
	}
	
	if(r>0 && g>0){
		for(int i=0;i<n;++i){
			if(s[i]=='r'){
				cout<<i+1<<endl;
				return;
			}
		}
	}
	if(b>0 && g>0){
		for(int i=0;i<n;++i){
			if(s[i]=='g'){
				cout<<i+1<<endl;
				return;
			}
		}
	}
	if(b>0 && r>0){
		for(int i=0;i<n;++i){
			if(s[i]=='b'){
				cout<<i+1<<endl;
				return;
			}
		}
	}
	
	cout<<1<<endl;
	
	return;
}


void solve2(){
	int q;cin>>q;
	while(q-->0){
		solve3();
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
	
	string s;cin>>s;
	if(s=="first"){
		int t;cin>>t;
		while(t-->0){
			solve1();
		}
		return 0;
	}else{
		int t;cin>>t;
		while(t-->0){
			solve2();
		}
		return 0;
	}
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
