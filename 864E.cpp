#include <bits/stdc++.h>
using namespace std;

struct Item{
    int t,d,p,id;
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vector<Item> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i].t>>a[i].d>>a[i].p;
        a[i].id = i;
    }

    sort(a.begin()+1,a.end(),[](const Item& x,const Item& y){
        return x.d<y.d;
    });

    const int MAXT = 2001;
    vector<vector<int>> dp(n+1,vector<int>(MAXT+1,-1));
    vector<vector<int>> take(n+1,vector<int>(MAXT+1,0));

    dp[0][0] = 0;
    for(int i=1;i<=n;++i){
        dp[i] = dp[i-1];

        for(int j=a[i].t;j<a[i].d;++j){
            if(dp[i-1][j-a[i].t]==-1)continue;
            int val = dp[i-1][j-a[i].t] + a[i].p;
            if(val>dp[i][j]){
                dp[i][j]=val;
                take[i][j]=1;
            }
        }
    }

    int best=0,bestj=0;
    for(int j=0;j<=MAXT;++j){
        if(dp[n][j]>best){
            best = dp[n][j];
            bestj = j;
        }
    }

    vector<int> ans;
    int j = bestj;
    for(int i=n;i>=1;--i){
        if(take[i][j]){
            ans.push_back(a[i].id);
            j -= a[i].t;
        }
    }

    reverse(ans.begin(),ans.end());

    cout<<best<<'\n'<<ans.size()<<'\n';
    for(int x:ans)cout<<x<<' ';
    cout<<'\n';

    return 0;
}