#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+7;

int pcnt,prime[N+10];
bool vis[N+10];
int sg[N+10];

void Sieve(int n){
    vis[1] = 1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++pcnt] = i;
            sg[i] = pcnt;
        }
        for(int j=1;j<=pcnt;++j){
            int p = prime[j];
            if(i*p>n)break;
            vis[i*p] = 1;
            sg[i*p] = j;
            if(i%p==0){
                break;
            }
        }
    }
}

int mgcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mgcd(b%a,a);
}

int mex(vector<int> a){
    sort(a.begin(),a.end());
    int cnt = 0;
    for(int x:a){
        if(x==cnt){
            cnt++;
        }
    }
    return cnt;
}

void Init(int n){
    sg[1] = 1;
    for(int i=2;i<=n;++i){
        vector<int> t;
        for(int j=1;j<=i-1;++j){
            if(mgcd(j,i)==1){
                t.push_back(sg[j]);
            }
        }
        sg[i] = mex(t);
    }
}

int SG(int x){
    int r = sg[x];
    if(r==0)return 1;
    if(r==1)return 0;
    return r;
}

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);for(int i=1;i<=n;++i)cin>>a[i];
    int xr=0;
    for(int i=1;i<=n;++i){
        xr ^= SG(a[i]);
    }
    if(xr){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
}

signed main(){
    Sieve(N);

    int t;cin>>t;
    while(t--){
        solve();
    }
}