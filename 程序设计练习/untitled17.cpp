#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;cin>>n>>x;
	int c=0;
	for(int i=1;i<=n;++i){
		int y=i;
		while(y){
			if(y%10 == x)c++;
			y/=10;
		}
	}
	cout<<c<<endl;
	
	return 0;
}
