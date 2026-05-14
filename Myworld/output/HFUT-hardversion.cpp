#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[5];

const ll M = 1e9+7;

signed main(){
    int n;cin>>n;
    string s;cin>>s;

    for(int i=0;i<n;++i){
        char c = s[i];
        if(c=='h'){
            dp[1]++;
        }else if(c=='f'){
            (dp[2] += dp[1])%=M;
        }else if(c=='u'){
            (dp[3] += dp[2])%=M;
        }else if(c=='t'){
            (dp[4] += dp[3])%=M;
        }
    }

    cout<<dp[4]<<endl;
    return 0;
}