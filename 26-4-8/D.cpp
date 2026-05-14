#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isarea(int n){
    int m = sqrt(n);
    m -= 10;
    for(int i=0;i<=20;++i){
        m++;
        if(m*m==n)break;
    }
    if(m*m==n){
        return 1;
    }else{
        return 0;
    }
}

signed main(){
    vector<int> a;
    int n;cin>>n;
    
    if(!isarea(n)){
        cout<<"No"<<endl;
        return 0;
    }

    while(n){
        a.push_back(n%10);
        n/=10;
    }

    int s = accumulate(a.begin(),a.end(),0);
    if(isarea(s)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

    return 0;
}