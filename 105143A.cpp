#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int& x:a)cin>>x;
    ll s=accumulate(a.begin(),a.end(),0);
    cout<<s<<endl;

    ll q=s/n,r=s%n;
    cout<<q<<" "<<r<<endl;
    return 0;
}