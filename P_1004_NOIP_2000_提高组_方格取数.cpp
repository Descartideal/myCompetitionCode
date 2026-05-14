#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 power(i64 x){
    i64 res = 1;
    for(int i=1;i<=x;++i){
        res *= i;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1,0));
    for(;;){
        int x,y,val;cin>>x>>y>>val;
        if(x==0 && y==0 && val==0)break;
        a[x][y] = val;
    }

    string s = string(n-1,'0')+string(n-1,'1');
    i64 limit = power(2*n-2)/power(n-1)/power(n-1);
    i64 res = 0;

    for(int i=1;i<=limit;++i){
        vector<vector<int>> b(n+1,vector<int>(n+1,0));
        i64 ans = 0;
        ans += a[1][1];b[1][1] = 1;
        int x=1,y=1;
        for(int j=0;j<2*n-2;++j){
            if(s[j]=='0'){
                ++x;
            }else{
                ++y;
            }

            ans += a[y][x];   b[y][x] = 1;
        }

        vector<vector<int>> c(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;++i){
            for(int j=n;j>=1;--j){
                if(b[i][j]==1)break;
                c[i][j] = a[i][j];
            }
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + c[i][j];
            }
        }

        ans+=dp[n][n];
        res  =  max(res,ans);
        next_permutation(s.begin(),s.end());
    }

    cout<<res<<endl;
    return 0;
}