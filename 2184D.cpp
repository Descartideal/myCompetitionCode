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
    int n,k;cin>>n>>k;
    vector<int> a(66,0);
    vector<int> b(68,0);
    int cnt = 0;
    while (n>0) {
        ++cnt;
        n = n/2;
    }
    --cnt;

    //cerr<<"cnt:"<<cnt<<endl;

    a[0] = 1;
    b[cnt+1] = 1;
    for(int i=1;i<=cnt;++i){
        for(int j=i;j<2*i;++j){
            b[j]+=a[j-i];
        }

        int cnt1 = 0;
        for(int j=0;j<=64;++j){
            if(a[j]==0){
                cnt1 = j;
                break;
            }
        }

        for(int j=cnt1+1;j>=1;--j){
            a[j] = a[j-1]+a[j];
        }
    }


    int res = 0;
    for(int i=k+1;i<=64;++i){
        res += b[i];
        if(b[i]==0){
            break;
        }
    }
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
