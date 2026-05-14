#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s;cin>>s;
    int n = s.size();
    s = ' '+s;

    vector<vector<int>> pal(n+1,vector<int>(n+1,0));
    vector<int> ans(n+2,0);
    for(int i=1;i<=n;++i){
        pal[i][i] = 1;
        ans[1]++;
    }
    for(int i=1;i<=n-1;++i){
        if(s[i]==s[i+1])pal[i][i+1]=2,ans[2]++;
    }

    for(int len=3;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            if(s[l]==s[r]){
                if(pal[l+1][r-1]){
                    int mid = (l+r)>>1;
                    pal[l][r] = pal[mid+1][r]+1;
                    ans[ pal[l][r] ]++;
                }
            }
        }
    }
    
    for(int i=n;i>=1;--i){
        ans[i] += ans[i+1];
    }

    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }

    return 0;
}