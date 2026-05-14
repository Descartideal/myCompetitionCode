#include <bits/stdc++.h>
using namespace std;

signed main(){
    int k;cin>>k;
    int t=0;
    for(int i=1;i<=k;++i){
        t = 10*t+7;
        t%=k;
        if(t==0){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}