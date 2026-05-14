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

using pii = pair<int,int>;


void solve(){
    int n;cin>>n;
    vector<pair<int,int>> tr(n+1);
    for(int i=1;i<=n;++i){
        cin>>tr[i].first>>tr[i].second;
    }
    int p = floor( log2(n) );

    auto f1 = [&](int x){
        tr[x].first=tr[x].second=0;
    } ;

    function<int(int,int,vector<pii>&)> fsolve;
    fsolve = [&](int root,int n,vector<pii>& tr){
        vector<int> siz(n+1,0),dep(n+1,0),fa(n+1,0);
        function<void(int,int)> dfs;
        dfs = [&](int x,int d){
            siz[x] = 1;
            dep[x] = d;
            auto [l,r]=tr[x];
            if(l)dfs(l,d+1);if(r)dfs(r,d+1);
            if(l){
                siz[x] += siz[l];
                fa[l] = x;
            }
            if(r){
                siz[x] += siz[r];
                fa[r] = x;
            }
        };
        dfs(root,1);

        auto query = [&](int u,int v){
            cout<<"? "<<u<<" "<<v<<endl;
            int r;cin>>r;
            return r;
        };

        int limit = n/2;

        int pos = 1;
        auto [l,r]=tr[pos];

        int fs=1,ls=siz[l],rs=siz[r];

        vector<pii> ans;
        while(1){
            auto [l,r]=tr[pos];
            ls=siz[l],rs=siz[r];
            fs = n-ls-rs;
            if(rs<=limit && ls<=limit){
                if(l && r){
                    int re = query(l,r);
                    if(re==0){
                        return fsolve(l,ls,tr);
                    }else if(re==2){
                        return fsolve(r,rs,tr);
                    }else{  
                        tr[pos] = {0,0};
                        return fsolve(root,fs,tr);
                    }
                }
                if(l){
                    int re = query(l,fa[pos]);
                    if(re==0){
                        return fsolve(l,ls,tr);
                    }else if(re==2){
                        tr[pos] = {0,0};
                        return fsolve(root,fs,tr);
                    }else{
                        return pos;
                    }
                }
                if(r){
                    int re = query(r,fa[pos]);
                    if(re==0){
                        return fsolve(r,rs,tr);
                    }else if(re==2){
                        tr[pos] = {0,0};
                        return fsolve(root,fs,tr);
                    }else{  
                        return pos;
                    }
                }
            }

            if(ls>rs){
                pos = l;
            }else{
                pos = r;
            }
        }

    };
    int ans = fsolve(1,n,tr);

    cout<<"! "<<ans<<endl;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}