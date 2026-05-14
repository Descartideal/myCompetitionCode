#include <bits/stdc++.h>
using namespace std;

signed main(){
    int a,b,c;cin>>a>>b>>c;
    vector<int> A(101);
    for(int i=1;i<=50;++i)A[i] = a;
    for(int i=51;i<=95;++i)A[i] = b;
    for(int i=96;i<=99;++i)A[i] = c;
    A[100] = c+1;
    
    cout<<100<<endl;
    for(int i=1;i<=100;++i){
        cout<<A[i]<<" ";
    }cout<<endl;
}