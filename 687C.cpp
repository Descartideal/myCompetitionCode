#include <bits/stdc++.h>
using namespace std;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return f*k;
}

const int N = 510;
bool dp[N][N];

int n,K;

signed main(){
    n=readint(),K=readint();
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        a[i] = readint();
    }

    for(int i=1;i<=n;++i){
        if(a[i]>K)continue;
        int x = a[i];

        for(int j=K-x;j>=0;--j){
            for(int k=0;k<=K;++k){
                if(dp[j][k]){
                    dp[j+x][x]=dp[j+x][k]=dp[j+x][k+x]=1;
                }
            }
        }
        dp[x][x] = 1;
    }


    vector<int> ans(1,0);
    for(int i=1;i<=K;++i){
        if(dp[K][i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}