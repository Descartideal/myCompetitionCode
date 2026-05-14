#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	function<void(char)> f;
	f = [&](char x){
		for(int i=0;i<n;++i){
			if(a[i][0]==x){
				cout<<x;
				f(a[i][1]);f(a[i][2]);
				break;
			}
		}
		return;
	};
	
	f(a[0][0]);
	
	return 0;
}
