#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node{
    int black=0,white=0;

    
};

ostream& operator<<(ostream& os,const node v){
    os<<v.black<<","<<v.white<<" ";
    return os;
}

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr

const int INF = 100000000000000007;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1,0);for(int i=1;i<=n;++i)cin>>a[i];
    vector<node> dp(n+1);
    vector<vector<int>> g(n+1);
    //vector<int> indeg(n+1,0),outdeg(n+1,0);
    for(int i=1;i<=n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    d(g)

    vector<int> fa(n+1,0);
    vector<int> cntSon(n+1,0);

    function<void(int,int)> dfs;
    dfs = [&](int x,int f){
        fa[x] = f;

        int sum = 0;
        int cntBlack = 0;
        int dmi = INF;
        for(int y:g[x]){
            if(y==f)continue;
            dfs(y,x);
            cntSon[x]++;

            if(dp[y].black<=dp[y].white){
                sum += dp[y].black;
                cntBlack++;
            }else{
                sum += dp[y].white;
                dmi = min(dmi,dp[y].black-dp[y].white);
            }
            
        }
        if(cntSon[x]==0){
            dp[x].black = a[x];
            dp[x].white = INF;
            return;
        }

        d(x)
        d(sum)

        dp[x].black = sum+a[x];
        if(cntBlack==0){
            dp[x].white = sum+dmi;
        }else{
            dp[x].white = sum;
        }
    };

    dfs(1,0);

    d(a)
    d(dp)

    
    cout<<min(dp[1].black,dp[1].white)<<endl;
}