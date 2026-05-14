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
    int n,T;cin>>n>>T;
    if(n==0){
        cout<<T;
        return;
    }
    vector<int> a(n);for(int& x:a)cin>>x;
    int state = 1;
    int last = 0;
    int ans = 0;
    for(int i=0;i<n;++i){
        if(state == 1){
            ans += a[i];
            state = 0;
            last = a[i];
        }
        if(state == 0){
            int diff = a[i]-last;
            if(diff>=100){
                ans += diff-100;
                last = a[i];
            }else{
                ;
            }
        }
    }

    int diff = T-last;
    if(diff>=100){
        ans += diff-100;
    }

    cout<<ans;


	return;
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
