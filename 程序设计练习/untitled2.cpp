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
	int n,k;cin>>n>>k;
	vector<int> a(n);for(int& x:a)cin>>x;
	vector<int> b(k+3,0);
	vector<int> c(n-k+1);
	
	int mex = 0;
	int mx = 0;
	
	/**

	for(int i=0;i<k;++i){
		int x = a[i];
		if(x>=k)continue;
		
		++b[x];
		if(x==mex){
			++mex;
			while(b[mex]!=0){
				++mex;
			}
		}
	}
	c[0] = mex;
	mx = max(mx,mex);
	
	for(int i=1;i+k<=n;++i){
		int x = a[i-1] , y = a[i+k-1];
		if(x<k){
			--b[x];
			if(x<=mex && b[x]==0){
				mex = x;
			}
		}
		
		if(y<k){
			++b[y];
			if(y==mex){
				++mex;
				while(b[mex]!=0){
					++mex;
				}
			}
		}
		
		c[i] = mex;
	}
	mx = max(mx,mex);
	
	cout<<min(mx,k-1)<<endl;
	
	**/
	
	for(int i=0;i<n;++i){
		int x = a[i];
		if(x>=k)continue;
		++b[x];
	}
	
	while(!b[mex]==0){
		++mex;
	}
	
	cout<<min(mex,k-1)<<endl;
	
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
