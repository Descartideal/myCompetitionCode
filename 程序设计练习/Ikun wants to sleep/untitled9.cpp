#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	int n;cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i){cin>>a[i];}
	if(a[1]==-1 && a[n]==-1){
		a[1]=0;
		a[n]=0;
	}
	
	if(a[1]==-1 && a[n]!=-1){
		a[1]=a[n];
	}
	
	if(a[1]!=-1 && a[n]==-1){
		a[n]=a[1];
	}
	
	cout<<abs(a[n]-a[1])<<endl;
	for(int i=1;i<=n;++i){
		if(a[i]==-1){
			cout<<0<<" ";
		}else{
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
	
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
