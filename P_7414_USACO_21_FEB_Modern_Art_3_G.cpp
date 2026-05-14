#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;++i){
        dp[i][i] = 1;
    }
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j = i+len-1;
            
            
            if(a[i]==a[j]){
                dp[i][j] = dp[i][j-1];
            }else{
                int ansMin = INF;
                for(int k=i;k+1<=j;++k){
                    ansMin = min(ansMin, dp[i][k]+dp[k+1][j]);
                }
                dp[i][j] = ansMin;
            }
        }
    }

    cout<<dp[1][n]<<endl;
    return 0;
}