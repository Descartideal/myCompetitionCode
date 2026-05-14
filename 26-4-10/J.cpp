#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define int long long

template<class T>
ostream& operator<<(ostream& os,const pair<T,T> v){
    os<<v.first<<","<<v.second<<" ";
    return os;
}

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    //os<<'\n';
    return os;
}


struct edge{
    int u,v;

    ostream& operator<<(ostream& os){
        os<<u<<','<<v<<" ";
        return os;
    }
};

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> f(n+1,0),w(k+1,0);
    for(int i=1;i<=n;++i){
        cin>>f[i];
        w[ f[i] ] = 1;
    }

    int canSee = 0;
    vector<int> cnt(k+1,0);
    vector<pair<int,int>> e;
    vector<unordered_map<int,int>> t(k+1);
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        if(w[u] && w[v]){
            canSee++;
            continue;
        }
        if(w[u] || w[v] || u==v){
            if(!w[u]){
                cnt[u]++;
            }else{
                cnt[v]++;
            }
            continue;
        }
        if(u>v)swap(u,v);
        e.push_back({u,v});
        t[u][v]++;
    }

    int ans = 0;
    for(auto [u,v]:e){
        if(u==v)continue;
        ans = max(ans,t[u][v]+cnt[u]+cnt[v]);
    }

    int mx=0,mx2=0;
    for(int i=1;i<=k;++i){
        if(cnt[i]>mx){
            mx2=mx;
            mx=cnt[i];
            continue;
        }
        if(cnt[i]>mx2){
            mx2=cnt[i];
        }
    }

    //d(e);
    //d(cnt);
    
    ans = max(ans,mx+mx2);
    //d(ans);cerr<<endl<<endl;
    cout<<ans+canSee<<"\n";
    
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}