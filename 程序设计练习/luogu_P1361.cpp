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

void solve(int n,int m){
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<tuple<int,int,int>>> b(n,vector<tuple<int,int,int>>(m,{0,0,0}));
	int sx,sy;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			char x;cin>>x;
			if(x=='.'){
				a[i][j] = 0;
			}else if(x=='#'){
				a[i][j] = 1;
			}else{
				a[i][j] = 2;
				sx = j;
				sy = i;
			}
		}
	}
	
	queue<tuple<int,int,int,int>> q;
	
	q.push({sx,sy,0,0});
	b[sy][sx] = {0,0,1};
	while(!q.empty()){
		auto [x,y,ix,iy] = q.front();
		q.pop();
		int nx,ny,nix,niy;
		for(int k=0;k<4;++k){
			nx = x+dx[k];
			ny = y+dy[k];
			nix = ix;
			niy = iy;
			if(nx<0){
				nx=m-1;
				nix--;
			}
			if(nx>=m){
				nx=0;
				nix++;
			}
			if(ny<0){
				ny=n-1;
				niy--;
			}
			if(ny>=n){
				ny=0;
				niy++;
			}
			
			if(a[ny][nx]==1)continue;
			if(b[ny][nx]==make_tuple(nix,niy,1))continue;
			if(b[ny][nx]==make_tuple(0,0,1)){
				cout<<"Yes"<<endl;
				return;
			}
			
			q.push({nx,ny,nix,niy});
			b[ny][nx] = {nix,niy,1};
		}
	}
	
	cout<<"No\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	while(cin>>n>>m){
		solve(n,m);
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
