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
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);g[v].push_back(u);
    }
    
    vector<int> he(n+1,0);
    vector<int> fa(n+1,0);
    int res = 0;

    function<int(int)> f;
    f = [&](int x){
        int sum = 0;
        bool j = 1;

        for(int& y:g[x]){
            if(y==fa[x])continue;
            fa[y] = x;

            sum += f(y);
            if(!(he[y]&1)){
                j=0;
            }
        }

        ++sum;
        he[x] = sum;

        if(  (((n-sum)&1) || x==1)   && j){
            ++res;
        }

        return sum;
    };

    f(1);
    cout<<res<<endl;

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
