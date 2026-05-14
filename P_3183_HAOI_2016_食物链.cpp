#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> h(n+1);
    vector<int> indeg(n+1,0),outdeg(n+1,0);
    for(int i=1;i<=m;++i){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        h[b].push_back(a);
        indeg[b]++;
        outdeg[a]++;
    }

    vector<int> dp(n+1,0);

    function<int(int)>dfs;
    dfs = [&](int x){
        int res = 0;
        for(int y:h[x]){
            if(dp[y]==0){
                dfs(y);
            }
            if(dp[y]==0){
                res+=1;
            }else{
                res+=dp[y];
            }
            
        }
        //if(res==0)res=1;
        dp[x] = res;

        return dp[x];
    };

    int ans = 0;
    for(int i=1;i<=n;++i){
        if(dp[i]==0)dfs(i);
        if(outdeg[i]==0){
            ans+=dp[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}