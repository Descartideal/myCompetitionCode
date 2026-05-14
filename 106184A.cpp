#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//#define int long long

ll powm(ll a,ll b,ll M){
    ll res = 1;
    ll x = a%M;
    while(b){
        if(b&1){res*=x;res%=M;}
        b>>=1;
        x = x*x;x%=M;
    }
    return res;
}

ll inv(ll x,ll M){
    return powm(x,M-2,M);
}


template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v)os<<x<<" ";
    return os;
}


struct bigint{
    vector<int> bint;
    int siz = 0;
    const int base = 100000000;

    void up(bigint& A){
        //cerr<<"asdf"<<endl;
        A.bint.push_back(0);
        A.siz++;
    }

    void selfadd(bigint& A,int dex,int x){
        if(x==0)return;
        while(A.siz-1<dex){
            up(A);
        }
        A.bint[dex] += x;
        if(A.bint[dex]>=base){
            selfadd(A,dex+1,A.bint[dex]/base);
            A.bint[dex] %= base;
        }
    }

    void create(bigint& A,int x){
        selfadd(A,0,x%base);
        selfadd(A,1,x/base);
    }

    void add(bigint& A,bigint& B){
        while(A.siz<B.siz){
            up(A);
        }
        
        int remain = 0;
        for(int i=0;i<B.siz;++i){
            A.bint[i] += (B.bint[i] + remain);
            remain = 0;
            if(A.bint[i]>=base){
                A.bint[i] -= base;
                remain += 1;
            }
        }
        if(remain>0){
            selfadd(A,B.siz,remain);       
        }
    }

    void mul(bigint& A,int x){
        ll remain = 0;
        for(int i=0;i<A.siz;++i){
            selfadd(A,i,(int)remain);
            ll t = A.bint[i];
            t *= x;
            remain = t/base;
            t %= base;
            A.bint[i] = t;
        }

        if(remain>0){
            selfadd(A,A.bint.size(),remain);
            //cerr<<"fdty"<<endl;
        }
    }

    ll mmod(bigint& A,ll M){
        ll res = 1;
        for(int i=0;i<A.siz;++i){
            res*=(A.bint[i]);res%=M;
            res*=powm(10,8*i,M);res%=M;
        }
        return res;
    }

    void print(){
        for(int i=(bint.size()-1);i>=0;--i){
            //if(bint[i]==0)continue;
            if(bint[i]==0){
                cout<<"00000000";
            }
            cout<<bint[i];
        }
    }


};

signed main(){
    bigint A;
    A.create(A,0);
    string s;cin>>s;

    int cnt = 0;
    int siz = 0;
    int t = 0;
    vector<int> u(8,0);
    for(int i=s.size()-1;i>=0;--i){
        u[cnt] = s[i]-'0';
        cnt++;
        if(cnt==8){
            cnt = 0;t = 0;
            for(int i=7;i>=0;--i){
                t = (t*10+u[i]);
            }
            A.selfadd(A,siz,t);
            siz++;
            t = 0;
            fill(u.begin(),u.end(),0);
        }
    }
    cnt = 0;t = 0;
    for(int i=7;i>=0;--i){
        t = (t*10+u[i]);
    }
    A.selfadd(A,siz,t);
    siz++;

    cout<<A.siz<<endl;
    A.print();
    //cout<<"adsf"<<endl;



    
    ll M1 = 998244353;
    vector<ll> power(1e6+1,1);
    for(int i=1;i<=1e6;++i){
        power[i]=power[i-1]*i;
        power[i]%=M1;
    }

    vector<ll> ans;
    ll y = inv( A.mmod(A,M1) , M1);
    for(int i=1;i<=1e6;++i){
        if(power[i]*y%M1 < i){
            //cerr<<"adf";
            ans.push_back(i);
        }
    }
    cerr<<ans<<endl;;




    ll M2 = 1e9+7;
    vector<ll> power2(1e6+1,1);
    for(int i=1;i<=1e6;++i){
        power2[i]=power2[i-1]*i;
        power2[i]%=M2;
    }

    vector<ll> ans2;
    ll y2 = inv( A.mmod(A,M2) , M2);
    for(int i=1;i<=1e6;++i){
        if(power[i]*y%M2 < i){
            //cerr<<"adf";
            ans2.push_back(i);
        }
    }

    cerr<<ans2;




    return 0;
}