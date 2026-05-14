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
	int n;
	i64 ax,ay,bx,by;
	cin>>n>>ax>>ay>>bx>>by;
	vector<i64>x(n),y(n);
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++) cin>>y[i];
	vector<pair<i64,i64>>p(n);
	for(int i=0;i<n;i++) p[i]={x[i],y[i]};
	sort(p.begin(),p.end());
	vector<pair<i64,i64>>s;
	for(int i=0;i<n;){
		i64 xx=p[i].first,lo=p[i].second,hi=p[i].second;
		int j=i;
		while(j<n&&p[j].first==xx){
			lo=min(lo,p[j].second);
			hi=max(hi,p[j].second);
			j++;
		}
		s.push_back({lo,hi});
		i=j;
	}
	i64 pl=ay,ph=ay;
	i64 dl=0,dh=0;
	for(auto [lo,hi]:s){
		i64 sp=hi-lo;
		i64 nl=sp+min(dl+llabs(pl-hi),dh+llabs(ph-hi));
		i64 nh=sp+min(dl+llabs(pl-lo),dh+llabs(ph-lo));
		dl=nl;dh=nh;
		pl=lo;ph=hi;
	}
	i64 vt=min(dl+llabs(pl-by),dh+llabs(ph-by));
	cout<<(bx-ax)+vt<<"\n";
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
