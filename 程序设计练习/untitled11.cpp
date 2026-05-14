#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int a=1<<(n-1);
	int max = -1;
	int max_i=-1;
	for(int i=1;i<=a;++i){
		int x;cin>>x;
		if(x>max){
			max = x;
			max_i = i;
		}
	}
	int max2 = -1;
	int max_j;
	for(int j=a+1;j<=2*a;++j){
		int x;cin>>x;
		if(x>max2){
			max2 = x;
			max_j = j;
		}
	}
	if(max>max2){
		cout<<max_j<<endl;
	}else{
		cout<<max_i<<endl;
	}
	
	return 0;
}
