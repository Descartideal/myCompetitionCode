#include <bits/stdc++.h>
using namespace std;
using ll = long long;


inline void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<"Fluttershy"<<endl;
        return;
    }
    if(n==2){
        cout<<"Pinkie Pie"<<endl;
        return;
    }
    int k = n%4;
    if(k==0){
        cout<<"Fluttershy"<<endl;
    }else if(k==1){
        cout<<"Fluttershy"<<endl;
    }else if(k==2){
        cout<<"Pinkie Pie"<<endl;
    }else{
        cout<<"Pinkie Pie"<<endl;
    }
    return;
}


int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}