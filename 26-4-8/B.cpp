#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

const int INF = 1e9+7;
const ll M = 998244353;

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}



ll mpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1)(res*=a)%=M;
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}

ll inv(ll x){
    return mpow(x,M-2);
}

void solve(){
    int n;cin>>n;
    int cnt1 = 0;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==-1){
            cnt1++;
        }
    }
    priority_queue<int,vector<int>,greater<int>> p;

    ll fu=1,fd=1;
    vector<int> bucket(n+1,0);
    int mi = 0;
    for(int i=1;i<=n;++i){
        int x = a[i];
        if(x==-1){
            int y = p.top();
            if(y<mi){
                cout<<0<<'\n';
                return;
            }
            mi = y;

            (fu*=bucket[y])%=M;
            (fd*=p.size())%=M;

            bucket[y]--;
            p.pop();
        }else{
            bucket[x]++;
            p.push(x);
        }
    }

    cout<<fu*inv(fd)%M<<'\n';

    return;
}


signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}