#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	long double s=0;
	for(int i=1;i<=n;++i){
		long double temp;cin>>temp;
		s+=temp;
	}
	s/=n;
	long double B=(long double)4.0/(long double)3.0;long double L=acos(-1)/2;
	if(abs(s-B)<abs(s-L)){
		cout<<"B";
	}else{
		cout<<"L";
	}
	
	
	return 0;
}
