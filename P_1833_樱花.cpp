#include <bits/stdc++.h>
using namespace std;

int readint(){
    int k=0,f=1,c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())k=10*k+(c&15);
    return k*f;
}

signed main(){
    int t1,t2,hh,mm;
    hh=readint(),mm=readint(),t1=hh*60+mm;
    hh=readint(),mm=readint(),t2=hh*60+mm;
    int T = t2-t1;int n;cin>>n;
    //cerr<<T<<" "<<n<<endl;

    vector<int> dp(T+1,0);

    for(int i=1;i<=n;++i){
        int t=readint(),c=readint(),p=readint();

        if(p==0){
            for(int j=t;j<=T;++j){
                dp[j] = max(dp[j] , dp[j-t]+c);
            }
            continue;
        }

        for(int k=1;k<=p;k<<=1){
            int time = k*t;
            int aesthetic = k*c;

            for(int j=T;j>=time;--j){
                dp[j] = max(dp[j] , dp[j-time]+aesthetic);
            }

            p-=k;
        }

        if(p==0)continue;
        int time = p*t;
        int aesthetic = p*c;
        for(int j=T;j>=time;--j){
            dp[j] = max(dp[j] , dp[j-time]+aesthetic);
        }
    }

    cout<<dp[T]<<endl;
    return 0;
}