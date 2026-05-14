#include <bits/stdc++.h>
using namespace std;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

int readint(){
    int k=0,f=1,c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())k=10*k+(c&15);
    return f*k;
}

signed main(){
    int n=readint(),m=readint();
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        a[i]=readint();
        a[i]%=m;
    }
    if(n>=m){
        cout<<"YES"<<endl;
        return 0;
    }
    bitset<2001> b;
    for(int i=1;i<=n;++i){
        int x = a[i];
        b = b|(b<<x)|(b>>(m-x));
        b[x]=1;
    }

    if(b[0] || b[m]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}