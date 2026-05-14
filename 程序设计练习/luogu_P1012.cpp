#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<string> a(n);for(auto& x:a)cin>>x;
	
	function<bool(string,string)> f;
	f = [&](string a,string b){
		int al=a.size(),bl=b.size();
		if(al>bl)return !f(b,a);
		if(bl>al){
			char x = a[al-1];
			for(int i=1;i<=bl-al;++i){
				a = a+x;
			}
			return f(a,b);
		}
		for(int i=0;i<al;++i){
			int x=a[i],y=b[i];
			cerr<<"asdf: "<<x<<" "<<y<<endl;
			if(x>y){
				cerr<<a<<">"<<b<<endl;
				return true;
			}
			if(x<y){
				cerr<<a<<"<"<<b<<endl;
				return false;
			}
		}
		return true;
	};
	
	sort(a.begin(),a.end(),f);
	
	/**

	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n;++j){
			if(!f(a[i],a[j])){
				swap(a[i],a[j]);
				
				cerr<<endl;
				for(int i=0;i<n;++i){
					cerr<<a[i]<<" ";
				}cerr<<endl;
			}
		}
	}
	
	**/
	
	for(int i=0;i<n;++i){
		cout<<a[i];
		cerr<<" ";
	}
}
