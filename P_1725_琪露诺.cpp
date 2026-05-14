#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

int main(){
    int n,L,R;cin>>n>>L>>R;
    vector<int> a(n+1);for(int& x:a)cin>>x;
    vector<int> dp(n+1,-1999999999);
    dp[0] = 0;
    deque<pii> d;

    //cerr<<"adsf"<<endl;


    for(int i=L;i<=n;++i){
        pii x = {dp[i-L],i-L};
        if(d.empty()){
            d.push_back(x);
        }else{
            while (!d.empty() && x.first>d.back().first) {
                d.pop_back();
            }
            d.push_back(x);
        }

        while(d.front().second<i-R){
            d.pop_front();
        }

        dp[i] = a[i]+d.front().first;

        //cerr<<i<<"-OK"<<d.front().first<<endl;
    }

    //cerr<<"ubh"<<endl;

/**
    for(int i=0;i<=n;++i){
        cerr<<dp[i]<<" ";
    }cerr<<endl;
**/

    int res = -1999999999;
    for(int i=max(L,n+1-R);i<=n;++i){
        res = max(res,dp[i]);
    }
    cout<<res<<endl;

    return 0;
}