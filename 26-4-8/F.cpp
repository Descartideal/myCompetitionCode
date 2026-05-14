#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

const int INF = 1e9+7;

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}

struct point{
    int i,j,d;
};

int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char c;cin>>c;
            //cerr<<c;
            if(c=='#'){
                a[i][j] = 1;
            }
        }//cerr<<endl;
    }
/**
    for(int i=1;i<=n;++i){
        cerr<<a[i]<<endl;
    }cerr<<endl;
 */
    //cerr<<a<<endl;

    vector<vector<int>> start(n+1,vector<int>(m+1,-1));
    auto bfs1 = [&](pair<int,int> x){
        queue<pair<int,int>> q;
        auto [i,j] = x;
        q.push(x);start[i][j] = 0;
        
        while(!q.empty()){
            auto y = q.front();q.pop();
            auto [i,j] = y;
            for(int k=0;k<4;++k){
                int ni=i+di[k],nj=j+dj[k];
                if(ni<1 || ni>n || nj<1 || nj>m ){
                    continue;
                }
                if(start[ni][nj]==-1 && a[ni][nj]==0){
                    start[ni][nj] = 0;
                    q.push({ni,nj});
                }
            }
        }
    };


    bfs1({1,1});

    //cerr<<start<<endl;

    if(start[n][m]==0){
        cout<<0<<'\n';
        return;
    }

    vector<vector<int>> end(n+1,vector<int>(m+1,-1));
    auto bfs2 = [&](pair<int,int> x){
        queue<pair<int,int>> q;
        auto [i,j] = x;
        q.push(x);end[i][j] = 0;
        
        while(!q.empty()){
            auto y = q.front();q.pop();
            auto [i,j] = y;
            for(int k=0;k<4;++k){
                int ni=i+di[k],nj=j+dj[k];
                if(ni<1 || ni>n || nj<1 || nj>m){
                    continue;
                }
                if(end[ni][nj]==-1 && a[ni][nj]==0){
                    end[ni][nj] = 0;
                    q.push({ni,nj});
                }
            }
        }
    };
    bfs2({n,m});

    vector<vector<int>> dist(n+1,vector<int>(m+1,-1));
    queue<point> q;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(start[i][j]==0){
                q.push({i,j,0});
                dist[i][j] = 0;
            }
        }
    }

    
    while(!q.empty()){
        auto [i,j,d] = q.front();q.pop();

        for(int k=0;k<4;++k){
            int ni=i+di[k],nj=j+dj[k];
            if(ni<1 || ni>n || nj<1 || nj>m){
                continue;
            }
            if(dist[ni][nj]==-1){
                dist[ni][nj] = d+1;
                q.push({ni,nj,d+1});
            }
        }
    }

    int ans = INF;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(end[i][j]==0){
                ans = min(ans,dist[i][j]);
            }
        }
    }
    
    cout<<ans-1<<endl;
}


signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}