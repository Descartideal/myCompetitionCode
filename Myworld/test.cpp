#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt = 0;
    for(int i=0;i<=n-4;++i){
        if(s.substr(i,4)=="hfut")cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}