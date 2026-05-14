#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

struct contest{
    int rank=0,score=0,cntk=0,realscore=0,dex=0;
};

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> io(n,vector<int>(m+1,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<=m;++j){
            cin>>io[i][j];
        }
    }

    

    vector<contest> a(n);
    for(int i=0;i<n;++i){
        a[i].rank = io[i][0];
        a[i].dex = i;
        for(int j=1;j<=m;++j){
            if(io[i][j]==-1){
                a[i].cntk++;
            }else{
                a[i].score += io[i][j];
            }
        }
    }

    
    


    bool greedyjudg;
    //从高到低贪心
    greedyjudg = 1;
    sort(a.begin(),a.end(),[&](auto A,auto B){
        if(A.rank!=B.rank){
            return A.rank>B.rank;
        }
        return (A.score+A.cntk*k)>(B.score+B.cntk*k);
    });

/**
    for(int i=0;i<n;++i){
        cerr<<a[i].dex<<" "<<a[i].rank<<" "<<a[i].score<<" "<<a[i].cntk<<" "<<a[i].realscore<<endl;
    }cerr<<endl;
 */

    a[0].realscore = a[0].cntk*k + a[0].score;
    for(int i=1;i<n;++i){
        if(a[i].rank != a[i-1].rank){
            a[i].realscore = min(a[i-1].realscore-1 , a[i].cntk*k+a[i].score);
        }else{
            a[i].realscore = min(a[i-1].realscore , a[i].cntk*k+a[i].score);
        }

        if(a[i].realscore<a[i].score){
            greedyjudg = 0;
            break;
        }
    }

    if(greedyjudg){
        for(int i=0;i<n;++i){
            int t = a[i].dex;
            int delta = a[i].realscore-a[i].score;
            for(int j=1;j<=m;++j){
                int& x = io[t][j];
                if(x==-1){
                    if(delta<=k){
                        x = delta;
                        delta = 0;
                    }else{
                        x = k;
                        delta -= k;
                    }
                }
            }
        }

        cout<<"Yes"<<endl;
        for(int i=0;i<n;++i){
            for(int j=1;j<=m;++j){
                cout<<io[i][j]<<" ";
            }cout<<endl;
        }
        return;
    }

    //从低到高贪心
    greedyjudg = 1;
    sort(a.begin(),a.end(),[&](auto A,auto B){
        if(A.rank!=B.rank)return A.rank>B.rank;
        return A.score+A.cntk*k>B.score+B.cntk*k;
    });

    a[n-1].realscore = a[n-1].score;
    for(int i=n-2;i>=0;--i){
        if(a[i].rank != a[i+1].rank){
            a[i].realscore = max(a[i+1].realscore+1,a[i].score);
        }else{
            a[i].realscore = max(a[i+1].realscore,a[i].score);
        }

        if(a[i].realscore>a[i].score+a[i].cntk*k){
            greedyjudg = 0;
            break;
        }
    }

    if(greedyjudg){
        for(int i=0;i<n;++i){
            int t = a[i].dex;
            int delta = a[i].realscore-a[i].score;
            for(int j=1;j<=m;++j){
                int& x = io[t][j];
                if(x==-1){
                    if(delta<=k){
                        x = delta;
                        delta = 0;
                    }else{
                        x = k;
                        delta -= k;
                    }
                }
            }
        }

        cout<<"Yes"<<endl;
        for(int i=0;i<n;++i){
            for(int j=1;j<=m;++j){
                cout<<io[i][j]<<" ";
            }cout<<endl;
        }
        return;
    }

    cout<<"No"<<endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}