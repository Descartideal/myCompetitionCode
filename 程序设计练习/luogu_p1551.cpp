#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,p;cin>>n>>m>>p;
	vector<int> a(n+1,0);
	vector<pair<int,int>> b(m),c(p);
	for(int i=0;i<m;++i){cin>>b[i].first>>b[i].second;}
	for(int i=0;i<p;++i){cin>>c[i].first>>c[i].second;}
	for(int i=0;i<=n;++i){a[i] = i;}
	
	function<int(int)> f;
	f = [&](int x){
		if(a[x] == x){
			return x;
		}else{
			a[x] = f(a[x]);
			return a[x];
		}
	};
	
	for(auto [x,y]:b){
		if(f(x) != f(y)){
			a[f(y)] = f(x);
		}
	}
	
	for(auto [x,y]:c){
		if(f(x)==f(y)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
