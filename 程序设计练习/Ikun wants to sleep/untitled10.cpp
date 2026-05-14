#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	int n;cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;++i){cin>>a[i];}
	for(int i=1;i<=n;++i){cin>>b[i];}
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
					cout<<"Ajisai"<<endl;
					return;
				}else{
					cout<<"Mai"<<endl;
					return;
				}
			}
		}
	}else{
		cout<<"Tie"<<endl;
		return;
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
