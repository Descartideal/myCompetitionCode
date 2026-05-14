#include <iostream>
using namespace std;
using uc = unsigned char;

int tr(char a){
	return a-'a'+1;
}

int main()
{
	string s;cin>>s;
	const int n=s.size();
	if(n==1){
		cout<<tr(s[0]);
		return 0;
	}
	int a[n+1]={0};
	a[0]=0;
	a[1]=tr(s[0]);
	for(int i=2;i<=n;++i){
		a[i]=max(a[i-1],a[i-2]+tr(s[i-1]));
	}
	cout<<a[n];
	return 0;
}
