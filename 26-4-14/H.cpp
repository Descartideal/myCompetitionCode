#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr


#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return k*f;
}

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(auto& x:v)os<<x<<" ";
    os<<endl;
    return os;
}

int lowbit(int x){
    return x&-x;
}

struct BIT{
    int n;
    vector<int> w;


    BIT(int n,const vector<int>& in):n(n),w(n+1){
        for(int i=1;i<=n;++i){
            add(i,in[i]);
        }
    }

    void add(int x,int v){
        for(;x<=n;x+=lowbit(x)){//cerr<<1<<endl;
            w[x] += v;
        }
    }

    int ask(int x){
        int ans = 0;
        for(;x;x-=lowbit(x)){
            ans += w[x];
        }
        return ans;
    }
    int ask(int l,int r){
        return ask(r)-ask(l-1);
    }

};


void solve(){
    int n=readint(),k=readint();
    int nStart = n;
    n = 1<<nStart;

    vector<int> a(n+1,0);for(int i=1;i<=n;++i)a[i]=readint();
    vector<int> b(n+1,0);for(int i=1;i<=n;++i)b[ a[i] ]=i;

    cerr<<a<<b<<endl;

    vector<int> w(n+1,1);
    w[0] = 0;
    BIT bit(n,w);

    cerr<<"asd"<<endl;

    vector<int> ans(n+1);

    for(int i=1;i<=n;++i){

        int x = b[i];
        int cnt = 0;
        bit.add(x,-1);
        d(x);
        
        for(int i=1;i<=n;++i){
            cerr<<bit.ask(i,i)<<" ";
        }cerr<<endl;

        for(int j=1;j<=nStart;++j){
            cnt++;
            int y = 1<<cnt;d(y)
            int l = ((x-1)/y)*y+1, r = ((x-1)/y+1)*y;

            cerr<<l<<" "<<r<<endl;
            int kk = bit.ask(l,r);
            int re = i-(y-kk);
            if(re<kk){
                cnt--;
                break;
            }

            if(k<kk){
                cnt--;
                break;
            }
        }
        
        ans[x] = cnt;
    }

    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

signed main(){
    solve();
    return 0;
}