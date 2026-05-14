#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<"\n";
#define cerr if(0)cerr

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
    
}

signed main(){
    solve();
    return 0;
}