#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr

void solve(){
    string s;cin>>s;
    int n = s.size();
    s = ' '+s;

    if(s[1]!='>'){
        cout<<"No"<<endl;
        return;
    }

    for(int i=n;i>=n-2;--i){
        if(s[i]!='>'){
            cout<<"No"<<endl;
            return;
        }
    }

    int cntPin = 0;
    int lastPinDex = 0;
    for(int i=2;i<=n-3;++i){
        if(s[i]=='-'){
            cntPin++;
            lastPinDex = i;
        }
    }

    d(lastPinDex);

    if(cntPin==0){
        cout<<"No"<<endl;
        return;
    }

    vector<pii> ans;
    for(int i=n-4;i>=lastPinDex-1;--i){
        ans.push_back({1,i+4});
    }

    for(int i=2;i<=lastPinDex-1;++i){

        d(i);
        char c = s[i];
        d(c);
        if(s[i]=='>'){
            cerr<<2384;
            ans.push_back({i,lastPinDex-i+4});
        }
    }

    cout<<"Yes "<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}