#include "bits/stdc++.h"
using namespace std;

static const int M1 = 1e9+7;
static const int M2 = 1e9+9;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<pair<int,int>> a;

    for(int i=1;i<=n;++i){
        string s;cin>>s;
        long long h1=0,h2=0;
        for(char c:s){
            h1 = (h1*131+h2+c)%M1;
            h2 = (h2*13331+h1+c)%M2;
        }
        a.push_back({(int)h1,(int)h2});
    }

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    cout<<a.size()<<endl;
    return 0;
}