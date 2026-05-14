#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	vector<int> b(n+1,0);
	vector<int> c(n+1,0);
	vector<int> v(n+1,0);
	
	stack<int> s;
	for(int i=1;i<=n;++i){
		if(b[i]!=0)continue;
		
		int x = i;
		int j = 1;
		while(b[x]==0 && v[x]==0){
			v[x] = j;
			s.push(x);
			
			x = a[x];
			++j;
		}
		if(b[x]==0){
			int last = s.top();s.pop();
			b[x] = 2;
			int loop_lenth = v[last]-v[x]+1;
			c[x] = loop_lenth;
			int loop_index = x;
			x = last;
			
			while(x!=loop_index){
				int last = s.top();s.pop();
				b[x] = 2;
				c[x] = loop_lenth;
				x = last;
			}
			
			int k = 1;
			while(!s.empty()){
				int last = s.top();s.pop();
				x = last;
				b[x] = 1;
				c[x] = loop_lenth+k;
				++k;
			}
		}else{
			int k = 1;
			int loop_lenth = c[x];
			while(!s.empty()){
				int last = s.top();s.pop();
				x = last;
				b[x] = 1;
				c[x] = loop_lenth+k;
				++k;
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		cout<<c[i]<<endl;
	}
	
	return 0;
}
