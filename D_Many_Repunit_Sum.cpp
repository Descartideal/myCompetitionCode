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
    vector<int>a(n+1);
    int m=0;
    for(int i=1;i<=n;++i){cin>>a[i];m=max(m,a[i]);}
    vector<ll>d(m+3);
    for(int i=1;i<=n;++i){int x=a[i];d[1]++;d[x+1]--;}
    vector<int>o;
    ll c=0,k=0;
    for(int i=1;i<=m;++i){
        c+=d[i];
        ll v=c+k;
        o.push_back(v%10);
        k=v/10;
    }
    while(k){o.push_back(k%10);k/=10;}
    for(int i=(int)o.size()-1;i>=0;--i)cout<<o[i];
    cout<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);

		solve();
	
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
