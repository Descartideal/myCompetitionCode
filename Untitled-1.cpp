#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int M1 = 1e9+7;
const int M2 = 1e9+9;


void solve(){
    int n;cin>>n;
    vector<pair<int,int>> a;
    a.reserve(n);
    int cnt = 0;
    for(int i=1;i<=n;++i){
        string s;cin>>s;int l = s.size();
        if(l>3){
            if(s.substr(l-3,3)=="-5G"){
                s=s.substr(0,l-3);
                ++cnt;
            }
        }

        long long h1=0,h2=0;
        for(char c:s){
            h1 = (h1*131+h2+c);
            h2 = (h2*13331+h1+c);
        }
        a.push_back({(int)h1,(int)h2});
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    cout<<cnt<<" ";
    cout<<n-a.size()<<endl;

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
