#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;cin>>n>>k;k%=n;
    
    if( (n%2==0) && (k&1) ){
        cout<<-1<<endl;
        return;
    }


    int ans = 0;
    for(int i=0;i<=2;++i){
        int t = i*n-k;
        if(t%2==0 && t>=0){
            ans = t/2;
            break;
        }
    }

    cout<<ans<<endl;
    return;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}