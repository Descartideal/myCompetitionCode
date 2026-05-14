#include <bits/stdc++.h>
using namespace std;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

const int INF = 1e9;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    vector<vector<int>> dp1(n+1,vector<int>(n+1,0)),dp2(n+1,vector<int>(n+1,INF));

    for(int i=1;i<=n;++i){
        dp1[i][i] = a[i];
        dp2[i][i] = 1;
    }

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            for(int k=l;k+1<=r;++k){
                if(dp1[l][k]==dp1[k+1][r] && dp1[l][k]!=0){
                    dp1[l][r] = dp1[l][k]+1;
                    break;
                }
            }
        }
    }
    //cerr<<dp1<<endl;

    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r = l+len-1;

            if(dp1[l][r]==0){
                for(int k=l;k+1<=r;++k){
                    dp2[l][r] = min(dp2[l][r], dp2[l][k]+dp2[k+1][r]);
                }
            }else{
                dp2[l][r] = 1;
                //cerr<<l<<" "<<r<<endl;
            }
        }
    }

    //cerr<<" "<<dp2<<endl;

    cout<<dp2[1][n]<<endl;


    return 0;
}