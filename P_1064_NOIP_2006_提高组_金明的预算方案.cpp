#include <bits/stdc++.h>
using namespace std;

const int N = 65;
const int M = 32005;

struct Item{
    int v,w;
};

int n,m;
Item mainItem[N];
vector<Item> attachs[N];
int dp[M];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int v,p,q;cin>>v>>p>>q;
        if(q==0){
            mainItem[i]={v,v*p};
        }else{
            attachs[q].push_back({v,v*p});
        }
    }

    for(int i=1;i<=m;++i){
        if(mainItem[i].v==0)continue;
        int v0 = mainItem[i].v, w0 = mainItem[i].w;
        
        for(int j=n;j>=v0;--j){
            dp[j]=max(dp[j],dp[j-v0]+w0);

            if(attachs[i].size()>=1){
                int v1 = attachs[i][0].v, w1 = attachs[i][0].w;
                if(j>=v0+v1){
                    dp[j]=max(dp[j],dp[j-v0-v1]+w0+w1);
                }
            }

            if(attachs[i].size()>=2){
                int v2 = attachs[i][1].v, w2 = attachs[i][1].w;
                if(j>=v0+v2){
                    dp[j]=max(dp[j],dp[j-v0-v2]+w0+w2);
                }
            }

            if(attachs[i].size()>=2){
                int v1 = attachs[i][0].v, w1 = attachs[i][0].w;
                int v2 = attachs[i][1].v, w2 = attachs[i][1].w;
                if(j>=v0+v1+v2){
                    dp[j]=max(dp[j],dp[j-v0-v1-v2]+w0+w1+w2);
                }
            }
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}