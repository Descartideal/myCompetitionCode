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
    string s;cin>>s;
    vector<int> a(n,0);
    for(int i=0;i<s.size();++i){
       if(s[i]=='A'){
            a[i]=1;
       }
       if(s[i]=='B'){
            a[i]=-1;
       }
    }

    vector<int> b(n+1,0);
    for(int i=1;i<=n;++i){
        b[i] = b[i-1]+a[i-1];
    }

    i64 ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            if(b[i]-b[j]>0){
                ++ans;
            }
        }
    }

    cout<<ans<<endl;


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
