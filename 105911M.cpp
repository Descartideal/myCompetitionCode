#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    k = n-k;
    string s = "";
    for(int i=0;i<k;++i){
        s = s+'2';
    }
    for(int i=k;i<n;++i){
        s = s+'3';
    }
    cout<<s<<endl;
}