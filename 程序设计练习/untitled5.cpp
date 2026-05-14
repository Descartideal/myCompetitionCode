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
	i64 n,m,k;cin>>n>>m>>k;
	vector<int> box(m);
	for(int i=0;i<m;++i) cin>>box[i];
	sort(box.begin(), box.end());
	
	struct Friend {
		int x;
		i64 y,z;
	};
	vector<Friend> f(n);
	i64 base = 0;
	for(int i=0;i<n;++i){
		cin >> f[i].x >> f[i].y >> f[i].z;
		base += f[i].y;
	}
	
	i64 remain = k - base;
	int happy = 0;
	vector<i64> need; 
	
	for(auto &fr : f){
		auto it = lower_bound(box.begin(), box.end(), fr.x);
		if(it != box.end()){
			happy++;
		} else {
			need.push_back(fr.z - fr.y);
		}
	}
	
	sort(need.begin(), need.end());
	for(auto cost : need){
		if(remain >= cost){
			remain -= cost;
			happy++;
		} else break;
	}
	
	cout << happy << "\n";
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
