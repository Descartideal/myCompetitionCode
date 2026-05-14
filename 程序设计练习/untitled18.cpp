#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
	i64 n,c;cin>>n>>c;
	unordered_map<i64,i64> a;
	for(int i=0;i<n;++i){
		i64 x;cin>>x;
		a[x]+=1;
	}
	
	unordered_set<i64> b;
	i64 res=0;
	
	for(auto [x,y]:a){
		auto it = b.find(x);
		if(it != b.end())continue;
		i64 t = x-c;
		
		auto it1 = a.find(t);
		if(it1 != a.end()){
			res += y*a[t];
			b.insert(x);
		}
	
		cerr<<"asdf:"<<x<<y<<endl;
	}
	
	cout<<res<<endl;
	return 0;
}
