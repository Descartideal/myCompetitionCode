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
    ll N,S;cin>>N>>S;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    int n1 = N / 2, n2 = N - n1;
    vector<ll> L, R;
    L.reserve(1LL << n1);
    R.reserve(1LL << n2);

    for(int mask=0; mask<(1<<n1); mask++){
        ll s=0;
        for(int i=0;i<n1;i++) if(mask>>i&1) s+=A[i];
        L.push_back(s);
    }

    for(int mask=0; mask<(1<<n2); mask++){
        ll s=0;
        for(int i=0;i<n2;i++) if(mask>>i&1) s+=A[n1+i];
        R.push_back(s);
    }

    sort(R.begin(), R.end());

    long long ans=0;
    for(ll x:L){
        ll need=S-x;
        auto it=equal_range(R.begin(),R.end(),need);
        ans+=it.second-it.first;
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
