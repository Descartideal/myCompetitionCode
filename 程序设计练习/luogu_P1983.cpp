#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> t(m+1);
	for(int i=0;i<m;++i){
		int s;cin>>s;
		for(int j=0;j<s;++j){
			int temp;cin>>temp;
			t[i].push_back(temp);
		}
	}
	
	for(int i=1;i<=n;++i){
		t[m].push_back(i);
	}
	
	function<int(int,int)> compare;
	compare = [&](int a,int b){
		int start = max(t[a][0],t[b][0]);
		int end = min(t[a].back(),t[b].back());
		
		if(start>end){
			return 0;
		}
		
		int i = lower_bound(t[a].begin(),t[a].end(),start) - t[a].begin();
		int j = lower_bound(t[b].begin(),t[b].end(),start) - t[b].begin();
		
		while(1){
			if(t[a][i]<t[b][j]){
				return -1;
			}
			if(t[a][i]>t[b][j]){
				return 1;
			}
			
			if(t[a][i]==end || t[b][j]==end){
				break;
			}
			++i;++j;
		}
		
		return 0;
	};
	
	vector<vector<int>> g(m+1);
	vector<int> ru(m+1,0);
	vector<int> chu(m+1,0);
	
	for(int i=0;i<m;++i){
		for(int j=i+1;j<=m;++j){
			int temp = compare(i,j);
			
			if(temp==-1){
				g[i].push_back(j);
				++ru[j];++chu[i];
			}
			if(temp==1){
				g[j].push_back(i);
				++ru[i];++chu[j];
			}
		}
	}
	
	
	int res = 0;
	vector<int> visited(m+1,0);
	queue<int> q,q1;
	
	for(int i=0;i<=m;++i){
		if(ru[i]!=0)continue;
		q.push(i);
	}
	
	while(!q.empty()){
		while(!q.empty()){
			int x = q.front();q.pop();
			visited[x]=0;
			chu[x] = 0;
			for(int y:g[x]){
				--ru[y];
				if(ru[y]==0){
					q1.push(y);
				}
			}
		}
		
		q = q1;
		q1 = queue<int>();
		++res;
	}

	cout<<res<<endl;
	
	return 0;
}
