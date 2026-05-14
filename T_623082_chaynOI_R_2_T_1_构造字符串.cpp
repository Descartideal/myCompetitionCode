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
    string s;cin>>s;int n = s.size();
    string t = "";
    vector<pair<int,string>> ans;

    auto f = [&](char x){
        t.push_back(x);
        if(x=='a'){
            ans.push_back({1,"a"});
        }else if(x=='b'){
            ans.push_back({1,"b"});
        }else{
            ans.push_back({1,"c"});
        }
        
    };

    auto g = [&](int i){
        t[i-1] = t[i-1]^t[i-2]^'a'^'b'^'c'; 
        ans.push_back({2,to_string(i)});
    };


    f('a');
    f('b');
    for(int i=3;i<=n;++i){
        f('c');
        g(i);
    }

    for(int i=n;i>=3;--i){
        if(t[i-1]==s[i-1])continue;
        if((t[i-1]^t[i-2]^'a'^'b'^'c')==s[i-1]){
            g(i);
            continue;
        }
        if((t[i-3]^t[i-2]^'a'^'b'^'c')==t[i-1]){
            g(i);
            g(i-1);
            g(i);
            continue;
        }
        g(i-1);
        g(i);
    }

    if(t[1]!=s[1]) g(2);
    
    cout<<ans.size()<<endl;
    for(int i=0;i<(int)ans.size();++i){
        cout<<ans[i].first<<" "<<(ans[i].second)<<endl;
    }

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
