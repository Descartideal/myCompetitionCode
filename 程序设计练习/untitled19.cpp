#include <bits/stdc++.h>
using namespace std;

string abc(const string a,const string b){
	if(a.empty())return "";
	
	char x = b.back();
	int pos = 0;
	while(a[pos]!=x){
		pos++;
	}
	
	string l1="",r1="",l2="",r2="";
	
	l1 = a.substr(0,pos);
	r1 = a.substr(pos+1);
	
	int n=l1.size();
	l2 = b.substr(0,n);
	r2 = b.substr(n,r1.size());
	
	return x+abc(l1,l2)+abc(r1,r2);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string b,c;cin>>b>>c;
	cout<<abc(b,c)<<endl;
	return 0;
}
