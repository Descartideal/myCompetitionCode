#include "bits/stdc++.h"
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);for(int& x:a)cin>>x;

    for(int i=0;i<n;++i){
        if(a[i]==k){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}