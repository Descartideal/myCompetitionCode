#include <bits/stdc++.h>
using namespace std;

int f(vector<int> a){
	vector<int> d;d.push_back(a[0]);
	
	int n = a.size()-1;
	for(int i=1;i<=n;++i){
		auto it = upper_bound(d.begin(),d.end(),a[i]);
		if(it==d.end()){
			d.push_back(a[i]);
		}else{
			*it = a[i];
		}
	}
	return d.size();
}

int rf(vector<int> a){
	vector<int> d;d.push_back(a[0]);
	
	int n = a.size()-1;
	for(int i=1;i<=n;++i){
		auto it = lower_bound(d.begin(),d.end(),a[i]);
		if(it==d.end()){
			d.push_back(a[i]);
		}else{
			*it = a[i];
		}
	}
	return d.size();
}

int main(){
	int x;
	vector<int> a;while(cin>>x){a.push_back(x);}
	
	int res2 = rf(a);
	reverse(a.begin(),a.end());
	int res1 = f(a);
	
	cout<<res1<<endl<<res2<<endl;
	
	return 0;
}
