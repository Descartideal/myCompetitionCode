#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n),b(n);for(int& x:a)cin>>x;for(int& x:b)cin>>x;
    vector<int> c(n);
    
    for(int i=0;i<n;++i){
        c[a[i]-1] = i+1;
    }
    for(int i=0;i<n;++i){
        b[i] = c[b[i]-1];
    }
    a=b;

    vector<int> dp;dp.push_back(a[0]);
    for(int i=1;i<n;++i){
        int x = a[i];
        auto it = upper_bound(dp.begin(),dp.end(),x);
        if(it == dp.end()){
            dp.push_back(x);
        }else{
            *it = x;
        }
    }

    cout<<dp.size()<<endl;

    return 0;
}