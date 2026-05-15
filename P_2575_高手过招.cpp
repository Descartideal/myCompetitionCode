#include <bits/stdc++.h>
using namespace std;

const int N = (1<<20)+10;
int sg[N+10];

inline int lowbit(int x){
    return x&-x;
}

void solve(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        int m;cin>>m;
        for(int j=1;j<=m;++j){
            int k;cin>>k;
            k = 20-k;
            a[i] += 1<<k;
        }
    }

    int xr = 0;
    for(int i=1;i<=n;++i){
        xr ^= sg[ a[i] ];
    }
    if(xr){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    for(int i=1;i<=(1<<20)-1;++i){
        if(lowbit(i)*2==i+1){
            continue;
        }
        bitset<20> b(i);
        vector<int> t;

        vector<int> dex(20,-1);
        int state = -1;
        for(int j=0;j<=19;++j){
            if(b[j]==0)state=j;
            if(b[j]==1)dex[j]=state;
        }
        for(int j=1;j<=19;++j){
            if(b[j]){
                if(dex[j]==-1)continue;
                int y = i-(1<<j)+(1<<dex[j]);
                t.push_back(sg[y]);
            }
        }
        sort(t.begin(),t.end());
        int cnt = 0;
        for(int x:t){
            if(cnt==x){
                cnt++;
            }
        }
        sg[i] = cnt;
    }

    int t;cin>>t;
    while(t--){
        solve();
    }
}