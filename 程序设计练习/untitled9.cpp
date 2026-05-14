#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int& x:a)cin>>x;
	sort(a.begin(),a.end());
	int t = -1;
	vector<int> d(n-1);
	int p=-1;
	for(int i=n-1;i>0;--i){
		int x = a[i]-a[i-1];
		d[i-1] = x;
		if(x == 0 && p==-1){
			p = i-1;
			t = a[p];
		}
	}
	
	
	if(p==-1){
		cout<<-1<<endl;
		return;
	}
	
	a.erase(a.begin()+p);a.erase(a.begin()+p);
	n -=2;
	for(int i=n-1;i>0;--i){
		int x = a[i]-a[i-1];
		d[i-1] = x;
	}
	
	int m = INT_MAX;
	int q = -1;
	for(int i=0;i<n-1;++i){
		if(d[i]<m){
			m=d[i];
			q = i;
		}
	}
	//写成屎山了（悲），懒得重构qwq
	cerr<<"m: "<<m<<" asdf: "<<t<<endl;
	cerr<<"q: "<<q<<endl;
	
	if(((double)m/2.0)+0.1<(double)t){
		cout<<a[q]<<" "<<a[q+1]<<" "<<t<<" "<<t<<endl;
	}else{
		cout<<-1<<endl;
	}
	
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
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

//————自由是遗忘的左伴随
