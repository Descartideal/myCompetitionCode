#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;cin>>s1>>s2;
	string s = s2+"#"+s1;
	cerr<<s<<endl;
	
	int l2=s2.size();
	
	int n = s1.size()+s2.size()+1;
	vector<int> a(n);
	
	a[0] = 0;
	for(int i=1;i<n;++i){
		int len=i;
		while(len){
			len = a[len-1];
			if(s[len]==s[i]){
				a[i] = len+1;
				break;
			}
		}
		if(a[i]==l2){
			cout<<i-2*l2+1<<endl;
		}
	}
	
	for(int i=0;i<l2;++i){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
