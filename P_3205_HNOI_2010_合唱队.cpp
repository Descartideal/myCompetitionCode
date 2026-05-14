#include<bits/stdc++.h>
using namespace std;

const int M = 19650827;
const int MAXN = 1005;

int dp[MAXN][MAXN][2];

int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    

    for(int i=1;i<=n;++i){
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            if(a[l]<a[l+1])dp[l][r][0]=(dp[l][r][0]+dp[l+1][r][0])%M;
            if(a[l]<a[r])dp[l][r][0]=(dp[l][r][0]+dp[l+1][r][1])%M;
            if(a[r]>a[l])dp[l][r][1]=(dp[l][r][1]+dp[l][r-1][0])%M;
            if(a[r]>a[r-1])dp[l][r][1]=(dp[l][r][1]+dp[l][r-1][1])%M;
        }
    }

    cout<<(dp[1][n][0]+dp[1][n][1])%M<<'\n';
    return 0;
}