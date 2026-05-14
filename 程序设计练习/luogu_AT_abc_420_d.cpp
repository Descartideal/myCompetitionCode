#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
const int INF = INT_MAX;

void solve(){
	
	int H,W;cin>>H>>W;
	vector<string> A(H);
	for(int i=0;i<H;++i){
		cin>>A[i];
	}
	cerr<<"asdf"<<endl;
	for(int i=0;i<H;++i){
		cerr<<A[i]<<endl;
	}
	
	int sx,sy,gx,gy;
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(A[i][j]=='S'){sx = j;sy = i;}
			if(A[i][j]=='G'){gx = j;gy = i;}
		}
	}
	vector<vector<array<int,2>>> dist(H,vector<array<int,2>>(W,{INF,INF}));
	queue<tuple<int,int,int>> q;
	
	q.push({sx,sy,0});
	dist[sy][sx][0] = 0;
	
	while(!q.empty()){
		auto [x,y,t] = q.front();
		q.pop();
		
		char c = A[y][x];
		if(c=='#')continue;
		if(c=='o' && t==1)continue;
		if(c=='x' && t==0)continue;
		
		int d = dist[y][x][t];
		if(x==gx && y==gy){
			cout<<d<<endl;
			return;
		}
		
		int nt=1;
		if(c=='?'){
			nt ^= t;
		}else{
			nt = t;
		}
	
		
		for(int k=0;k<4;++k){
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(nx<0 || nx>=W || ny<0 || ny>=H)continue;
			char cc = A[ny][nx];
			
			if(cc=='#')continue;
			if(cc=='o' && nt==1)continue;
			if(cc=='x' && nt==0)continue;
			
			if(dist[ny][nx][nt]>d+1){
				dist[ny][nx][nt] = d+1;
				q.push({nx,ny,nt});
			}
		}
	}
	cout<<-1<<endl;
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
