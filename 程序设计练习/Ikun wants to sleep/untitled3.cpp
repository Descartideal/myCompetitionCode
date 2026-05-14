#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

using ldd = long double;

i64 abc(i64 n){
	return n-floor((sqrtl((long double)n)));
}

void re(i64 xx){
	long double x = xx;
	i64 r = sqrtl(x);
	if(r*r == xx || (r+1)*(r+1) == xx || (r-1)*(r-1) == xx ){
		cout<<xx-1<<endl;
	}else{
		cout<<xx<<endl;
	}
}


void solve(){
	i64 k;cin>>k;
	if(k==1){cout<<2<<endl;return;}
	i64 l,r,mid;
	l=k,r=2*k;
	while(1){
		mid = (l+r)/2;
		if(abc(mid)==k){
			re(mid);
			return;
		}
		if(abc(mid)<k){
			l=mid;
		}else{
			r=mid;
		}
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
