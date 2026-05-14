#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main(){
    i64 n,k;cin>>n>>k;
    vector<vector<i64>> a(n+1);
    for(int i=1;i<=n;++i){
        a[i].push_back(0);
        for(int j=1;j<=i;++j){
            i64 x;cin>>x;
            a[i].push_back(x);
        }
    }

    i64 res = LONG_LONG_MIN/4;

    if(k>=n){
        vector<vector<i64>> dp(n+1);
        dp[1].push_back(0);dp[1].push_back( max( a[1][1] , 3*a[1][1] ) );
        for(int i=2;i<=n;++i){
            dp[i].push_back(0);
            for(int j=1;j<=i;++j){
                dp[i].push_back(  max(dp[i-1][min(j,i-1)],dp[i-1][max(j-1,1)])  +  max(a[i][j],3*a[i][j])  );
            }
        }
        res = *max_element(dp[n].begin()+1,dp[n].end());
        cout<<res<<endl;
    }else{
        vector<vector<unordered_map<i64,i64>>> dp(n+1);
        dp[1].push_back( {{0LL,0LL}} );dp[1].push_back( {{k,a[1][1]}} );if(k>0)dp[1][1][k-1]=3*a[1][1];

        for(i64 i=2;i<=n;++i){
            dp[i].push_back( {{0LL,0LL}} );
            for(i64 j=1;j<=i;++j){
                for(int kk=0;kk<=min(i,k);++kk){
                    if(kk==0){
                        dp[i].push_back( {{  k , max(dp[i-1][min(j,i-1)].at(k),dp[i-1][max(j-1,1LL)].at(k)) + a[i][j]  }} );
                    }else{
                        i64 t1 =
                        max( dp[i-1][min(j,i-1)].at(max(k-kk,k-i+1)) , dp[i-1][max(j-1,1LL)].at(max(k-kk,k-i+1)) ) 
                        + a[i][j];
                        
                        i64 t2 = max(  dp[i-1][min(j,i-1)].at(k-kk+1) , dp[i-1][max(j-1,1LL)].at(k-kk+1)  ) + 3*a[i][j];
                        dp[i][j][k-kk] = max(t1,t2);
                    }
                }
            }
        }

        //cerr<<"adf"<<endl;

        for(int i=1;i<=n;++i){
            for(int kk=0;kk<=k;++kk){
                res = max( res , dp[n][i].at(kk) );
            }
        }
        cout<<res<<endl;
    }

    return 0;
}