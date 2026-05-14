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
    vector<int> a(n);for(int& x:a)cin>>x;
    vector<int> L;
    sort(a.begin(),a.end());
    int m=a[0],M=a.back();

    int c=0;
    for(int i=a.size()-1;i>=0;--i){
        if(a[i]==M)c++;
        else break;
    }
    vector<int> b={a.begin(),a.end()-c};int l = b.size();
    bool j = 1;
    if(l&1){
        j=0;
    }
    for(int i=0;i<l;++i){
        if(b[i]+b[l-i-1]!=M){
            j=0;
            break;
        }
    }
    if(j){
        L.push_back(M);
    }

    int k = a[0]+a.back();
    j = 1;l=a.size();
    if(l&1){
        j=0;
    }
    for(int i=0;i<l;++i){
        if(a[i]+a[l-i-1]!=k){
            j=0;
            break;
        }
    }
    if(j){
        L.push_back(k);
    }

    sort(L.begin(),L.end());
    for(int i=0;i<L.size();++i){
        cout<<L[i]<<" ";
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
