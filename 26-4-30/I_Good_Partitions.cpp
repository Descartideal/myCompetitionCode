#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define cerr if(0)cerr
#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(auto x:v)os<<x<<" ";
    os<<"\n";
    return os;
};

struct Fenwick{
    //private:

    inline int lowbit(int x){
        return (x & (-x));
    }

    int n;vector<int> a;


    //public:

    Fenwick(int _n,const vector<int>& w){
        n = _n;
        a.resize(n+1,0);
        for(int i=1;i<=n;++i){//cerr<<i<<endl;
            add(i,w[i]);
        }
    }

    void add(int pos,int val){
        for(;pos<=n;pos+=lowbit(pos)){//d(lowbit(pos));d(n);
            a[pos] += val;
        }
    }

    ll sumf(int pos){
        ll res = 0;
        for(;pos;pos-=lowbit(pos)){
            res += a[pos];
        }
        return res;
    }
};


void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1);for(int i=1;i<=n;++i)cin>>a[i];
    vector<int> diff(n);for(int i=1;i<=n-1;++i)diff[i]=a[i+1]-a[i];
    vector<int> sig(n,0);for(int i=1;i<=n-1;++i)if(diff[i]>=0)sig[i]=1;
    vector<int> total(n,0);
    for(int i=2;i<=n-1;++i){
        int cyc = (n-1)/i;
        int remain = (n-1)%i;
        total[i] = cyc*(i-1)+remain;
    }

    cerr<<7<<endl;

    vector<vector<int>> factor(n+1);
    for(int i=2;i<=n;++i){
        for(int j=1;j<=n;++j){
            ll x = i*j;
            if(x>n)break;
            factor[x].push_back(i);
        }
    }

    vector<int> cnt0(n,0);
    Fenwick bit(2*n+1,vector<int>(2*n+1,0));cerr<<7<<endl;
    bit.add(0+n,n-1);

    cerr<<7<<endl;
    d(cnt0);

    int Tcnt0 = 0;

    auto f = [&](int x,int tsig){
        if(tsig){
            bit.add(cnt0[x]+n,-1);
            cnt0[x]--;
            bit.add(cnt0[x]+n,1);
        }else{

            bit.add(cnt0[x]+n,-1);
            cnt0[x]++;
            bit.add(cnt0[x]+n,1);
        }
    };

    auto g = [&](int i,int tsig){
        if(tsig==0){
            Tcnt0++;
            for(int x:factor[i]){
                f(x,1);    
            }
        }else{
            Tcnt0--;
            for(int x:factor[i]){
                f(x,0);    
            }
        }
    };

    for(int i=1;i<=n-1;++i){
        if(sig[i]==0){
            g(i,0);
        }
    }

    /** 
    for(int i=1;i<=2*n;++i){
        cout<<bit.sumf(i)-bit.sumf(i-1)<<" ";
    }cout<<endl;
    d(Tcnt0);
*/
    
    cout<<bit.sumf((-Tcnt0)+n)+1<<endl;

    for(int i=1;i<=m;++i){
        int dex,data;cin>>dex>>data;
        a[dex] = data;
        if(dex>=2){
            int tsig;
            if(a[dex-1]<=data){
                tsig = 1;
            }else{
                tsig = 0;
            }
            if(sig[dex-1]!=tsig){
                g(dex-1,tsig);
                sig[dex-1] = tsig;
            }
        }
        if(dex<=n-1){
            int tsig;
            if(data<=a[dex+1]){
                tsig = 1;
            }else{
                tsig = 0;
            }
            if(sig[dex]!=tsig){
                g(dex,tsig);
                sig[dex] = tsig;
            }
        }
        cout<<bit.sumf((-Tcnt0)+n)+1<<endl;

/** 
        for(int i=1;i<=2*n;++i){
            cout<<bit.sumf(i)-bit.sumf(i-1)<<" ";
        }cout<<endl;
        d(Tcnt0);*/
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}