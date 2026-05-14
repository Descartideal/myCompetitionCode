#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
	string s;cin>>s;
	int n;n=s.size();
	if(n==1){
		cout<<1<<"\n";
		return;
	}
	if(n==2){
		if((s[0]=='*'||s[0]=='>')&&(s[1]=='*'||s[1]=='<')){
			cout<<"-1\n";
			return;
		}
	}
	for(int i=0;i<n-1;++i){
		if((s[i]=='*'||s[i]=='>')&&(s[i+1]=='*'||s[i+1]=='<')){
			cout<<"-1\n";
			return;
		}
	}
	int left = 0;
	int right = 0;
	
	int i=0;
	while(1){
		if(s[i]=='<'){
			left++;
		}else{
			break;
		}
		if(i==n-1){
			break;
		}else{
			++i;
		}
	}
	
	i=n-1;
	while(1){
		if(s[i]=='>'){
			right++;
		}else{
			break;
		}
		if(i==0){
			break;
		}else{
			--i;
		}
	}
	
	if(n-left-right==0){
		cout<<max(left,right)<<"\n";
	}else{
		cout<<max(left,right)+1<<"\n";
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
