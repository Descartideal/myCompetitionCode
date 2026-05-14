#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

struct y{
    int t,v;
};

int main(){
    int t,m;cin>>t>>m;
    vector<y> a(m+1);
    for(int i=1;i<=m;++i){
        cin>>a[i].t>>a[i].v;
    }

    vector<vector<int>> dp(m+1,vector<int>(t+1,0));
    for(int i=1;i<=m;++i){
        dp[i]=dp[i-1];
        for(int j=a[i].t;j<=t;++j){
            dp[i][j] = max( dp[i-1][j] , dp[i-1][j-a[i].t] + a[i].v );
            //cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
/**
    for(int i=1;i<=m;++i){
        cerr<<dp[i]<<endl;
    }
 */
    cout<<dp[m][t]<<endl;

    return 0;
}