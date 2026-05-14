#include <bits/stdc++.h>
using namespace std;

#define int long long

inline int lowbit(int x){
    return x&-x;
}

void solve(){
    int n;cin>>n;
    cout<<lowbit(n)<<endl;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}