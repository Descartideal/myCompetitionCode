#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int ,int >;

const int N = 1e6+10;

vector<int> a(N,0);

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}


int solve2(string s){
    int n = s.size();

    vector<pii> a(n,{0,0});

    int cnt = 0;
    for(int i = 0;i<n-1;++i){
        if(s[i] == s[i+1]){
            if(a[i].first==0 && a[i].second==0){
                cnt++;
                a[i] = a[i+1] = {cnt,i};
            }else{
                a[i+1] = a[i];
            }
        }
    }

    vector<int> b(n,0);
    for(int i=0;i<n;++i){
        b[ a[i].first ]++;
    }

    cerr<<b<<endl;

    int ans = 0;
    for(int i=1;i<=cnt;++i){
        ans += (b[i]/2);
    }

    return ans;
}




void solve(){
    string s;cin>>s;
    cout<<solve2(s)<<endl;
    return;
}





signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}