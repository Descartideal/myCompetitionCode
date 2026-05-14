#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n+1);
	vector<int> b(n+1);
	vector<int> ru(n+1,-1);
	
	function<int(int)> dfs;
	dfs = [&](int x){
		if(b[x]==1)return 1;
		b[x] = 1;
		for(int y:g[x]){
			if(dfs(y))return 1;
		}
		b[x]=2;
		return 0;
	};
	
	for(int i=1;i<=m;++i){
		string s;cin>>s;
		int u = s[0]-'A'+1;
		int v = s[2]-'A'+1;
		g[u].push_back(v);
		if(ru[v]==-1)ru[v]=0;
		if(ru[u]==-1)ru[u]=0;
		ru[v]++;
		
		
		b = vector<int>(n+1,0);
		if(dfs(u)){
			cout<<"Inconsistency found after "<<i<<" relations."<<endl;
			return 0;
		}
		
		if(i<n-1)continue;
		
		cerr<<"iu"<<endl;
		
		int judg = 0;
		for(int j=1;j<=n;++j){
			if(ru[j]==-1){
				judg = 1;
				break;
			}
		}
		if(judg){
			continue;
		}
		
		
		vector<int> r(ru);
		cerr<<"adsf"<<endl;
		cerr<<endl<<"nidong: ";
		for(int k=1;k<=n;++k){
			cerr<<r[k]<<" ";
		}cerr<<endl;
		
		
		queue<int> q;
		for(int j=1;j<=n;++j){
			int ru0=0,ru0i=0;
			for(int ii=1;ii<=n;++ii){
				if(r[ii]==0){
					ru0++;
					ru0i = ii;
				}
			}
			if(ru0>1){
				cerr<<"momingqimiao"<<endl;
				judg = 1;
				break;
			}
			int x = ru0i;
			for(int y:g[x]){
				r[y]--;
			}
			r[x] = -1;
			q.push(x);
			
			cerr<<endl<<"nidong: ";
			for(int k=1;k<=n;++k){
				cerr<<r[k]<<" ";
			}cerr<<endl;
		}
		if(judg)continue;
		
		cout<<"Sorted sequence determined after "<<i<<" relations: ";
		for(int j=1;j<=n;++j){
			cout<<(char)('A'-1+q.front());
			q.pop();
		}
		cout<<".";
		return 0;
	}
	
	cout<<"Sorted sequence cannot be determined."<<endl;
	return 0;
}
