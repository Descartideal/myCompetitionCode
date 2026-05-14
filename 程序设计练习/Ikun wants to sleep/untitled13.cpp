#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	int n,a;cin>>n>>a;
	vector<int> A(n);for(int& x:A){cin>>x;}
	i128 m = accumulate(A.begin(),A.end(),0LL);
	
	auto it0 = lower_bound(A.begin(),A.end(),a);
	auto it = upper_bound(A.begin(),A.end(),a);
	
	int left,right;
	
	if(*it0 )
	if(*it0 == a){
		left = it0-A.begin();
		right = A.end()-it0-1;
	}else{
		left = it-1-A.begin();
		right = A.end()-it-1;
	}

	if(left>=right){
		cout<<a-1<<endl;
	}else{
		cout<<a+1<<endl;
	}
	
	
	
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
