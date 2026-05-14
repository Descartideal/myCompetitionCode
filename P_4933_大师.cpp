#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 Z = 998244353;

i64 res = 0;

void add(i64 x){
    res = (res+x)%Z;
}

int main(){
    i64 n;cin>>n;
    vector<i64> a(n);for(i64& x:a)cin>>x;
    vector<unordered_map<i64,i64>> dp(n);

    i64 cnt = 0;
    for(int i=0;i<n;++i){
        cnt++;
        for(int j=i-1;j>=0;--j){
            dp[i][a[i]-a[j]] += dp[j][a[i]-a[j]]+1;
            dp[i][a[i]-a[j]] %= Z;

            cnt += dp[j][a[i]-a[j]]+1;
            cnt %= Z;
        }
    }

    cout<<cnt<<endl;
    return 0;
}