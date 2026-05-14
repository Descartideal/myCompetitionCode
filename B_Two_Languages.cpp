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
    int N,M;cin>>N>>M;
    string s1,s2;cin>>s1>>s2;
    unordered_map<char,int> u1,u2;
    for(int i=0;i<s1.size();++i){
        char x = s1[i];
        ++u1[x];
    }
    for(int i=0;i<s2.size();++i){
        char x = s2[i];
        ++u2[x];
    }



    int n;cin>>n;
    for(int i=0;i<n;++i){
        string s;cin>>s;
        bool j1=1,j2=1;
        for(int i=0;i<s.size();++i){
            char x = s[i];
            if(u1[x]==0){
                j1=0;
            }
            if(u2[x]==0){
                j2=0;
            }
        }

        if(j1==0 && j2==1){
            cout<<"Aoki"<<endl;
        }else if(j1==1 && j2==0){
            cout<<"Takahashi"<<endl;
        }else{
            cout<<"Unknown"<<endl;
        }
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
