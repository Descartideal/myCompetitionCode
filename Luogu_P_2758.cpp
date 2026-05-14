#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;cin>>a>>b;
    int al=a.size(),bl=b.size();

    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
    for(int i=0;i<=bl;++i){
        dp[0][i] = i;
    }

    for(int i=0;i<=al;++i){
        dp[i][0] = i;
    }

    for(int i=1;i<=al;++i){
        for(int j=1;j<=bl;++j){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }

    cout<<dp[al][bl]<<endl;


    return 0;
}