#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	int n; cin>>n;
	vector<i64>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<i64> pref(n+1,0);
	for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
	vector<i64> abc(n+1);
	i64 min = 0;
	i64 max1 = 0;
	for(i64 i=1;i<=n;++i){
		abc[i]=i*(i+1)-pref[i];
		i64 temp = abc[i]-min;
		if(temp>max1){
			max1 = temp;
		}
		if(abc[i]<min){
			min = abc[i];
		}
	}
	i64 res = accumulate(a.begin(),a.end(),0LL)+max1;
	cout<<res<<"\n";
	
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
