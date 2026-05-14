#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

const ll M = 998244353;

void solve(){
    string s;cin>>s;int n = s.size();
    ll dpCnt[2] = {0,1};
    ll dpSum[2] = {0,0};

    for(char c:s){
        int limit = c-'0';
        
        ll ndpCnt[2] = {0,0};
        ll ndpSum[2] = {0,0};

        for(int tight = 0;tight <= 1;tight++){
            int maxDigit;

            if(tight==1){
                maxDigit = limit;
            }else{
                maxDigit = 9;
            }

            for(int d = 0;d<=maxDigit;++d){
                int ntight;
                if(tight==1 && d==limit){
                    ntight = 1;
                }else{
                    ntight = 0;
                }

                ndpCnt[ntight] = (ndpCnt[ntight]+dpCnt[tight])%M;

                ndpSum[ntight] =
                    (ndpSum[ntight]+dpSum[tight]+dpCnt[tight]*d)%M;
            }
        }

        dpCnt[0] = ndpCnt[0];
        dpCnt[1] = ndpCnt[1];
        dpSum[0] = ndpSum[0];
        dpSum[1] = ndpSum[1];
    }

    cout<<(dpSum[0]+dpSum[1])%M<<endl;

}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


    /**
    vector<vector<ll>> dp(n+1,vector<ll>(10,0));
    ll cnt = 0;
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        char c = s[i-1];
        int h = c-'0';
        for(int j=0;j<=9;++j){
            dp[i][j] = cnt;
        }
        for(int j=0;j<=h;++j){
            dp[i][j]++;
        }

        cnt = (cnt)*10+h;
    }
    vector<ll> ans(10,0LL);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=9;++j){
            ans[j] += dp[i][j];
            ans[j] %= M;
        }
    }

    ll res = 0;
    for(int i=1;i<=9;++i){
        res += i*ans[i];
        res %= M;
    }
    cerr<<" "<<dp<<endl;
    cerr<<ans<<endl;
    cout<<res<<endl;
    */