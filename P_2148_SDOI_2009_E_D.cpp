#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int x){
    return __builtin_ctz(x);
}

int sg(int a,int b){
    return s( ((a-1)|(b-1))+1 );
}

void solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);for(int i=1;i<=n;++i)cin>>a[i];
    n/=2;
    vector<int> b(n+1,0);for(int i=1;i<=n;++i)b[i]=sg(a[2*i-1],a[2*i]);
    int s = 0;
    for(int i=1;i<=n;++i){
        s ^= b[i];
    }
    if(s){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}