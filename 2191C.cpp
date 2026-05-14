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

    {
    bool j = 0;bool k=1;
    for(int i=0;i<n;++i){
        if(s[i]=='0' && j==0)continue;
        if(s[i]=='1' && j==0){
            j=1;
            continue;
        }
        if(s[i]=='0' && j==1){
            cout<<"Alice"<<endl;
            k=0;
            break;
        }
    }
    if(k){
        cout<<"Bob"<<endl;
        return;
    }
    }


    int cnt = 0;
    int i=0,j=n-1;
    vector<int> ans1,ans2;
    while (1) {
        while (s[i]=='0' && i<n) {
            ++i;
        }
        while (s[j]=='1' && j>=0) {
            --j;
        }

        if(i<j){
            ans1.push_back(i+1);
            ans2.push_back(j+1);

            ++i;
            --j;
        }else{
            break;
        }
    }
    cout<<ans1.size()+ans2.size()<<endl;
    for(int i=0;i<ans1.size();++i){
        cout<<ans1[i]<<" ";
    }
    for(int i=ans2.size()-1;i>=0;--i){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;

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
