#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 100000;
const int MAXW = 200000;

signed main(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];b[i]*=k;
    }

    vector<int> dp(2*OFFSET+5,0);
    for(int i=1;i<=n;++i){
        int w=a[i]-b[i],v=a[i];
        
        if(w>=0){
            for(int j=MAXW;j>=w;--j){
                if(dp[j-w]==0)continue;
                dp[j] = max(dp[j],dp[j-w]+v);
            }
        }else{
            for(int j=0;j<=MAXW+w;++j){
                if(dp[j-w]==0)continue;
                dp[j] = max(dp[j],dp[j-w]+v);
            }
        }

        dp[OFFSET+w]=max(dp[OFFSET+w],v);
    }

    if(dp[OFFSET]==0){
        cout<<-1<<endl;
        return 0;
    }

    cout<<dp[OFFSET]<<endl;
    return 0;
}