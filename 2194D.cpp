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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1, vector<int>(m+1,0));
    vector<vector<int>> pref(n+1, vector<int>(m+1,0));
    int cnt = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            cnt += a[i][j];
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
        }
    }

    ll best = -1;
    int bi = 1, bj = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll x = pref[i][j];
            ll y = cnt - x;
            if(x * y > best){
                best = x * y;
                bi = i;
                bj = j;
            }
        }
    }
    cout<<best<<endl;

    string ans;
    ans.append(bj-1, 'R');
    ans.append(bi-1, 'D');
    ans.append(m-bj, 'R');
    ans.append(n-bi, 'D');

    cout<<ans<<endl;
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
