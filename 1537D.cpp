#include <bits/stdc++.h>
using namespace std;
/**
const int N = 1e6+7;
int a[N+100];

bool isVictory(int x){
    vector<int> factor;
    for(int i=2;i<=x-1;++i){
        if(x%i==0){
            factor.push_back(i);
        }
    }
    for(int y:factor){
        if(a[x-y]==0){
            return 1;
        }
    }
    return 0;
}

signed main(){
    int n=1000;
    a[4] = 1;
    for(int i=5;i<=n;++i){
        if(isVictory(i)){
            a[i] = 1;
        }
    }

    for(int i=0;i<=n/10;++i){
        cout<<10*i+1<<":";
        for(int j=1;j<=10;++j){
            cout<<a[i*10+j]<<" ";
        }cout<<endl;
    }


    return 0;
}
 */


int lowbit(int x){
    return x&-x;
}

void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<"Bob"<<endl;
        return;
    }

    if(lowbit(n)==n){
        int cnt = 0;
        while(n){
            cnt++;
            n>>=1;
        }
        if(cnt&1){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
        return;
    }

    if(n&1){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}