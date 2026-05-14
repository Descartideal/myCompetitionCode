#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

struct item{
    int w,d;
};

int main(){
    int n,m;cin>>n>>m;
    vector<int> dp(m+1,0);
    vector<item> a(n+1,{0,0});
    for(int i=1;i<=n;++i){
        cin>>a[i].w>>a[i].d;
    }

    for(int i=1;i<=n;++i){
        //cerr<<dp<<endl;
        //cerr<<a[i].d<<" "<<a[i].w<<endl;
        for(int j=m;j>=a[i].w;--j){//cerr<<j<<endl;
            dp[j] = max(dp[j] , dp[j-a[i].w] + a[i].d );
        }
        //cerr<<dp<<endl<<endl;
    }

    cout<<dp[m]<<endl;

    return 0;
}