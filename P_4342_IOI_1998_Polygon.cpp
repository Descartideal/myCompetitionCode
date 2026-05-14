#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

signed main(){
    int n;cin>>n;
    
    int m = 2*n;
    vector<char> op(m+1);
    vector<ll> val(m+1,0);

    for(int i=1;i<=n;++i){
        cin>>op[i]>>val[i];
        op[i+n]=op[i];
        val[i+n]=val[i];
    }

    vector<vector<ll>> mx(m+1,vector<ll>(m+1,-INF));
    vector<vector<ll>> mn(m+1,vector<ll>(m+1,INF));

    for(int i=1;i<=m;++i){
        mx[i][i] = mn[i][i] = val[i];
    }

    for(int len = 2;len<=n;++len){
        for(int l=1;l+len-1<=m;++l){
            int r = l+len-1;

            for(int k=l;k+1<=r;++k){
                if(op[k+1]=='t'){
                    mx[l][r] = max(mx[l][r], mx[l][k]+mx[k+1][r]);
                    mn[l][r] = min(mn[l][r], mn[l][k]+mn[k+1][r]);
                }else{
                    ll a = mn[l][k]*mn[k+1][r];
                    ll b = mn[l][k]*mx[k+1][r]; 
                    ll c = mx[l][k]*mn[k+1][r];
                    ll d = mx[l][k]*mx[k+1][r];
                    mx[l][r] = max({mx[l][r],a,b,c,d});
                    mn[l][r] = min({mn[l][r],a,b,c,d});
                }
            }
        }
    }

    ll ans = -INF;
    vector<int> res;

    for(int i=1;i<=n;++i){
        ll cur = mx[i][i+n-1];
        if(cur>ans){
            ans = cur;
            res.clear();
            res.push_back(i);
        }else if(cur==ans){
            res.push_back(i);
        }
    }

    cout<<ans<<'\n';
    for(int i=0;i<res.size();++i){
        if(i)cout<<' ';
        cout<<res[i];
    }
    return 0;
}