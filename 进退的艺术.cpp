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
    i64 n,m;cin>>n>>m;
    vector<pair<i64,i64>> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second = i;
    }
    vector<i64> e(n+1,0);

    sort(a.begin()+1,a.end());
    vector<int> b(n+1,0);
    vector<i64> pre(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i] = pre[i-1]+a[i].first;
        b[i] = a[i].first;
    }

    auto f = [&](i64 a,i64 b){
        if(a>b)return 0LL;
        return pre[b]-pre[a-1];
    };

    for(int i=1;i<=n;++i){
        i64 t = m-b[i];
        i64 s = upper_bound(b.begin()+1,b.end(),t)-b.begin();
        
        i64 index = a[i].second;
        i64& res = e[index];


        res += (s-1)*b[i];
        res -= f(s,n);

        if(s>i){
            res -= b[i];
        }else{
            res += b[i];
        }
    }

    for(int i=1;i<=n;++i){
        cout<<e[i]<<" ";
    }cout<<endl;

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
