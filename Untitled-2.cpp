#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll =long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

using ld = long double;

ld f(ld x){
    return x>0?x:0;
}

void solve(){
    ld A,B,k,v,l,r;cin>>A>>B>>k>>v>>l>>r;
//    A*=1000;B*=1000;
// k*=100;v*=100;
//    l*=1000;r*=1000;

    ld ans;
    if(A<l){
        ans = f(B-(l-A)/k)/(2*v);
    }else if(l<=A && A<r){
        ans = B/2/v+(A-l)/k/v/2;
    }else{
        ans = f( (B+((A-l)/k))/(2*v)  - (A-r)/(k*v) );
    }

    ans*=1000;
    cout<<(ll)llround(ans)<<endl;

	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
    int t;cin>>t;
    while (t--) {
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
