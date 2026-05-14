#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i)cin>>a[i];
    if(a[1]+a[2]<=a[n]){
        cout<<"1 2 "<<n<<endl;
        return;
    }
    cout<<-1<<endl;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}