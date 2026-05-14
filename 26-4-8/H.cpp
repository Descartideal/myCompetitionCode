#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}

void test(){
    int n = 10000;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        a[i] = i*(i+1);
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int k=j+1;k<=n;++k){
                if(a[i]*a[j]==a[k]){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
}

void solve(){
    int x=readint(),l=readint(),r=readint();
    cout<<r-l+1<<endl;
}


signed main(){
    //test();
    int t=readint();
    while(t--){
        solve();
    }

    return 0;
}