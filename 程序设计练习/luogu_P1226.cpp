#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
	i64 a,b,p;cin>>a>>b>>p;
	cout<<a<<"^"<<b<<" mod "<<p<<"=";
	
	i64 res = 1;
	while(b){
		if(b&1){
			res = (res*a)%p;
		}
		b>>=1;
		a = a*a%p;
	}
	cout<<res<<endl;
	
	return 0;
}
