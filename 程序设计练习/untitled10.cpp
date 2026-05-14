#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	int r;cin>>r;
	int index=1;
	for(int i=0;i<n*m-1;++i){
		int x;cin>>x;
		if(x>r)index++;
	}
	
	cerr<<"asdf:"<<index<<endl;
	
	int j=index/n;int k=index%n;
	if(j & 1){
		cout<<j+1<<" "<<n+1-k;
	}else{
		cout<<j+1<<" "<<k;
	}
	
	return 0;
}
