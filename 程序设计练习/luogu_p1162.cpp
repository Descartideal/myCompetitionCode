#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

bool bfs(vector<vector<int>>& a,int n){
	int judg = 1;
	int sx,sy;
	for(int i=0;i<n;++i){if(a[0][i]==0){sy=0;sx=i;judg=0;}}
	for(int i=0;i<n;++i){if(a[n-1][i]==0){sy=n-1;sx=i;judg=0;}}
	for(int i=0;i<n;++i){if(a[i][0]==0){sy=i;sx=0;judg=0;}}
	for(int i=0;i<n;++i){if(a[i][n-1]==0){sy=i;sx=n-1;judg=0;}}
	if(judg){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(a[i][j]==0)a[i][j]=2;
				if(a[i][j]==3)a[i][j]=0;
			}
		}
		return 0;
	}else{
		queue<pair<int,int>>q;
		q.push({sx,sy});
		while(!q.empty()){
			auto [x,y] = q.front();
			q.pop();
			int& c = a[y][x];
			c=3;
			for(int k=0;k<4;++k){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
				int cc = a[ny][nx];
				if(cc==1 || cc==3)continue;
				q.push({nx,ny});
			}
		}
	}
	return 1;
}

void solve(){
	int n;cin>>n;
	vector<vector<int>> a(n,vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	
	while(bfs(a,n)){
		;
	}
	
	for(int i=0;i<n;++i){
		if(i)cout<<"\n";
		for(int j=0;j<n;++j){
			if(j)cout<<" ";
			cout<<a[i][j];
		}
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
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
