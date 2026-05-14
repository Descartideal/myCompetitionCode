#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int a[N+100];

void solve(){
    int n;cin>>n;
    if(a[n]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    
    for(int i=1;i<=9;++i){
        a[i] = 1;
    }
    for(int i=10;i<=N;++i){
        vector<int> t;
        int x = i;
        while(x){
            int y = x%10;
            x/=10;
            if(y==0)continue;
            t.push_back(y);
        }

        vector<int> tt;
        sort(t.begin(),t.end());
        tt.push_back(t[0]);
        tt.push_back(t.back());
        t.clear();

        for(int y:tt){
            if(y==0)continue;
            if(a[i-y]==0){
                a[i] = 1;
            }
        }
    }


    int t;cin>>t;
    while(t--){
        solve();
    }
}