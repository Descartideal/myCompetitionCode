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
    i64 n,x;cin>>n>>x;
    vector<vector<i64>> a(n,{0,0,0,0,0});
    for(auto& x:a){
        cin>>x[1]>>x[2]>>x[3];
        x[0] = x[1]*x[2]-x[3];
        x[4] = (x[2]-1)*(x[1]);
    }

    sort(a.begin(),a.end(),[&](const auto& A,const auto& B){
        if(A[0]==B[0]){
            return (A[1]<B[1]);
        }
        return (A[0]>B[0]);
    });

    i64 b = a[0][0];
    i64 c = 0;
    for(auto& x:a){
        c+=x[4];
    }

    if(c>=x){
        cout<<0<<endl;
        return;
    }

    if(b<=0){
        cout<<-1<<endl;
        return;
    }


    i64 cnt = (x-c)/b;
    i64 r = (x-c)%b;
    if(r>0){
        ++cnt;
    }
    cout<<cnt<<endl;

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
