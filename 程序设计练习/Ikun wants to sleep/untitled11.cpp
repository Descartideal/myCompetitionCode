#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int hbp(int n) {
	if (n == 0) return -1;
	return 31 - __builtin_clz(n);
}

int abc(vector<int> a,vector<int> b,int n){
	int j=0;
	for(int i=1;i<=n;++i){
		j^=a[i];
		j^=b[i];
	}
	if(j){
		for(int i=n;i>=1;i--){
			int k = a[i]^b[i];
			if(k){
				if(i&1){
					return 1;
				}else{
					return 2;
				}
			}
		}
	}else{
		return 0;
	}
	
	return 0;
}


void solve(){
	int n;cin>>n;
	vector<int> a(n+1),b(n+1);
	int max=INT_MIN;
	for(int i=1;i<=n;++i){cin>>a[i];if(a[i]>max){max=a[i];};}
	for(int i=1;i<=n;++i){cin>>b[i];if(b[i]>max){max=b[i];};}
	
	int m = hbp(max);
	vector<int> c(n+1),d(n+1);
	for(;m>=1;--m){
		int k = 1<<m;
		for(int i=1;i<=n;++i){c[i]=(a[i]&k)>>m;}
		for(int i=1;i<=n;++i){d[i]=(b[i]&k)>>m;}
		int t = abc(c,d,n);
		if(t==1){
			cout<<"Ajisai"<<endl;
			return;
		}
		if(t==2){
			cout<<"Mai"<<endl;
			return;
		}
	}
	for(int i=1;i<=n;++i){c[i] = a[i]&1;}
	for(int i=1;i<=n;++i){d[i] = b[i]&1;}
	int t = abc(c,d,n);
	if(t==1){
		cout<<"Ajisai"<<endl;
		return;
	}
	if(t==2){
		cout<<"Mai"<<endl;
		return;
	}
	cout<<"Tie"<<endl;
	return;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}


















/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
