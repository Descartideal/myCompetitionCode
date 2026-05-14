#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = (1LL << 61);

signed main(){
    int n,c;cin>>n>>c;

    vector<int> x(n+1),w(n+1);
    for(int i=1;i<=n;++i){
        cin>>x[i]>>w[i];
    }

    vector<int> sum(n+1,0);
    for(int i=1;i<=n;++i){
        sum[i] = sum[i-1]+w[i];
    }

    static i64 dp[55][55][2];
    for(int i=0;i<55;++i){
        for(int j=0;j<55;++j){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    dp[c][c][0] = dp[c][c][1] = 0;

    for(int len=1;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            if(dp[l][r][0]==INF && dp[l][r][1]==INF)continue;

            int turned_off = sum[r] - sum[l-1];
            int remain = sum[n] - turned_off;

            if(l>1){
                dp[l-1][r][0] = min(
                    dp[l-1][r][0],
                    dp[l][r][0] + 1LL*(x[l]-x[l-1])*remain
                );
                dp[l-1][r][0] = min(
                    dp[l-1][r][0],
                    dp[l][r][1] + 1LL*(x[r]-x[l-1])*remain
                );
            }

            if(r<n){
                dp[l][r+1][1] = min(
                    dp[l][r+1][1],
                    dp[l][r][1] + 1LL*(x[r+1]-x[r])*remain
                );
                dp[l][r+1][1] = min(
                    dp[l][r+1][1],
                    dp[l][r][0] + 1LL*(x[r+1]-x[l])*remain
                );
            }
        }
    }

    cout<<min(dp[1][n][0],dp[1][n][1])<<'\n';
    return 0;
}