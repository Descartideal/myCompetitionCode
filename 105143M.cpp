#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5+10;

unordered_map<ll,ll> t;

int main(){
    ll n;cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;++i){
        ll x;cin>>x;
        t[x]++;
        a[i] = x;
    }
    sort(a.begin()+1,a.end(),greater<ll>());

    stack<ll> s;

    function<bool(ll)> f;
    f = [&](ll v){
        if(v==0)return false;
        if(t[v]!=0){
            s.push(v);
            t[v]--;
            return true;
        }
        if(v&1){
            return ( f(v>>1) && f(v-(v>>1)) );
        }
        return false;
    };

    vector<ll> ans;
    for(int i=1;i<=n;++i){
        if( (a[i]&1) || t[a[i]]==0)continue;
        ll v=a[i];

        t[v]--;
        if(f(v+1)){
            while(!s.empty())s.pop();
            ans.push_back(2*v+1);
            continue;
        }
        t[v]++;
        while(!s.empty()){
            ll x = s.top();s.pop();
            t[x]++;
        }

        t[v]--;
        if(f(v-1)){
            while(!s.empty())s.pop();
            ans.push_back(2*v-1);
            continue;
        }
        t[v]++;
        while(!s.empty()){
            ll x = s.top();s.pop();
            t[x]++;
        }
    }

    for(auto [x,y]:t){
        while(y--){
            ans.push_back(x);
        }
    }


    sort(ans.begin(),ans.end(),greater<ll>());

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}