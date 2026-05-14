#include <bits/stdc++.h>
using namespace std;

signed main(){
    vector<int> a(6);
    int cnt = 0;
    for(int i=0;i<6;++i){
        cin>>a[i];
        if(a[i])cnt++;
    }
    if(cnt==3){
        cout<<"Congratulations on graduation!"<<endl;
    }else{
        cout<<"Songfes in Japan..."<<endl;
    }
}