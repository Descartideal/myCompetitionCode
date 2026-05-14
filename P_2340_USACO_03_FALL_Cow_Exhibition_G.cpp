#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 400000;
const int MAXS = 800000;
const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> s(n+1,0),f(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>s[i]>>f[i];
    }
    
    vector<int> dp(MAXS+5,-INF);
    dp[OFFSET] = 0;
    for(int i=1;i<=n;++i){//cerr<<7;
        if(s[i]>=0){
            for(int j=MAXS-s[i];j>=0;--j){
                if(dp[j]>-INF){
                    dp[ j+s[i] ] = max( dp[ j+s[i] ]  ,  dp[j]+f[i] );
                }
            }
        }else{
            for(int j=-s[i];j<=MAXS;++j){
                if(dp[j]>-INF){
                    dp[j+s[i]] = max( dp[j+s[i]]  ,  dp[j]+f[i] );
                }
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<=OFFSET;++i){
        if(dp[i+OFFSET]<0)continue;
        ans = max(ans,dp[i+OFFSET]+i);
    }
    cout<<ans<<endl;

    return 0;
}