#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int main(){
	int n,m,sx,sy;
	cin>>n>>m>>sx>>sy;
	vector<vector<int>> s(n+1,vector<int>(m+1,-1));
	
	queue<pair<int,int>> q;
	q.push({sx,sy});s[sx][sy] = 0;
	int step = 0;
	while(!q.empty()){
		auto [x,y] = q.front();q.pop();
		step = s[x][y];
		
		for(int k=0;k<8;++k){
			if(x+dx[k]<=0 || x+dx[k]>n || y+dy[k]<=0 || y+dy[k]>m)continue;
			if(s[x+dx[k]][y+dy[k]]==-1){
				q.push({x+dx[k],y+dy[k]});s[x+dx[k]][y+dy[k]] = step+1;
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
