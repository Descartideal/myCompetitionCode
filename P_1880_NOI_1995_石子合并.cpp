#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

template <class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}

int main(){
    int n;cin>>n;
    vector<int> a(2*n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n] = a[i];
    }

    vector<int> pre(2*n+1,0);
    for(int i=1;i<=2*n;++i){
        pre[i] = pre[i-1]+a[i];
    }

    vector<vector<int>> dpi(2*n+1,vector<int>(2*n+1,0));
    vector<vector<int>> dpm(2*n+1,vector<int>(2*n+1,0));

    for(int len=1;len<=2*n-1;++len){
        for(int i=1;i+len<=2*n;++i){
            int j=i+len;
            dpi[i][j] = INF;

            for(int k=i;k<j;++k){
                dpi[i][j] = min(dpi[i][j] , dpi[i][k] + dpi[k+1][j] + (i==j?0:(pre[j]-pre[i-1])) );
                dpm[i][j] = max(dpm[i][j] , dpm[i][k] + dpm[k+1][j] + (i==j?0:(pre[j]-pre[i-1])) );
            }
        }
    }

    int ansMin=INF,ansMax=0;
    for(int i=1;i<=n+1;++i){
        ansMin = min(ansMin , dpi[i][i+n-1]);
        ansMax = max(ansMax , dpm[i][i+n-1]);
    }

    cout<<ansMin<<endl<<ansMax;
    return 0;
}