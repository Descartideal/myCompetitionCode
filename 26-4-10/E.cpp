#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define int long long

inline int lowbit(int x){
    return x&-x;
}

struct fenwick{
    vector<int> f;
    int n;

    void update(int pos,int val){
        for(;pos<=n;pos+=lowbit(pos)){
            f[pos]+=val;
        }
    }

    int sumf(int pos){
        int res = 0;
        for(;pos;pos-=lowbit(pos)){
            res += f[pos];
        }
        return res;
    }

    fenwick(int _n,const vector<int>& a){
        n = _n;
        f.resize(n+1,0);
        for(int i=1;i<=n;++i){
            if(!a[i])continue;
            update(i,1);
        }
    }

};

void solve(){
    int n,k;cin>>n>>k;
    int nStart = n, kStart = k;
    string s;cin>>s;
    if(k>n){
        k=n;
    }
    s = s+s.substr(0,k);
    s = ' '+s;
    n += k;
    //cerr<<s<<endl;
    vector<int> a(n+1,0);
    for(int i=7;i<=n;++i){
        if(s.substr(i-6,7)=="nanjing"){
            a[i]=1;
        }
    }
/** 
    fenwick f(n,a);
    int ans = 0;
    for(int i=nStart;i<=n;++i){
        ans = max(ans,f.sumf(i)-f.sumf(i-nStart));
    }
*/
    int res = 0;
    int ans = 0;
    for(int j=1;j<=n;++j){
        int i=j-nStart;
        if(i>=1){
            if(a[i]){
                ans--;
            }
        }
        if(a[j]){
            ans++;
        }

        res = max(ans,res);
    }


    cout<<ans<<"\n";
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}