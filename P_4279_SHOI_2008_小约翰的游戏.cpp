#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);for(int i=1;i<=n;++i)cin>>a[i];

    bool judg=0;
    for(int i=1;i<=n;++i){
        if(a[i]!=1){
            judg = 1;
            break;
        }
    }
    
    if(judg){
        int xr = 0;
        for(int i=1;i<=n;++i){
            xr ^= a[i];
        }
        cout<<(xr?"John":"Brother")<<endl;
    }else{
        cout<<(n&1?"Brother":"John")<<endl;
    }
}


signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}