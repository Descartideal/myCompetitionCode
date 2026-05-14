#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

signed main(){
    int n,W;cin>>n>>W;
    vector<int> dp(W+1,0);
    for(int i=1;i<=n;++i){
        int v,w,m;cin>>v>>w>>m;
        for(int k=1;k<=m;k<<=1){//cerr<<7;
            int cnt = k;
            int weight = cnt*w , value = cnt*v;
            //cerr<<cnt<<" "<<weight<<" "<<value<<endl;
            for(int j=W;j>=weight;--j){//cerr<<'a';
                dp[j] = max(dp[j],dp[j-weight]+value);
            }//cerr<<dp<<endl;

            m-=cnt;
        }

        if(m<=0)continue;
        int weight = m*w;
        int value = m*v;
        for(int j=W;j>=weight;--j){
            dp[j] = max(dp[j],dp[j-weight]+value);
        }
    }

    cout<<dp[W]<<endl;
    return 0;
}