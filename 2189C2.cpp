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
    if(n&1){
        cout<<n-1<<" ";
        for(int i=2;i<=n-1;++i){
            cout<<(i^1)<<" ";
        }
        cout<<1<<endl;
    }else{
        bool j=1;
        int t;
        for(int i=2;i<n;++i){
            t = i^n;
            if(2<=t && t<n && (t&1)){
                t = t^n;
                j = 0;
                break;
            }
        }

        if(j){
            cout<<-1<<endl;
            return;
        }

        cout<<t<<" ";
        for(int i=2;i<=n-1;++i){
            if(i==t-1){
                cout<<n<<" ";
                continue;
            }
            cout<<(i^1)<<" ";
        }
        cout<<1<<endl;
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
