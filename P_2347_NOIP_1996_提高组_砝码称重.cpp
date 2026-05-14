#include <bits/stdc++.h>
using namespace std;

signed main(){
    int a1,a2,a3,a5,a10,a20;cin>>a1>>a2>>a3>>a5>>a10>>a20;
    bitset<1005> b;
    for(int i=1;i<=a1;++i){
        b = b|(b<<1);b[1]=1;
    }
    for(int i=1;i<=a2;++i){
        b = b|(b<<2);b[2]=1;
    }
    for(int i=1;i<=a3;++i){
        b = b|(b<<3);b[3]=1;
    }
    for(int i=1;i<=a5;++i){
        b = b|(b<<5);b[5]=1;
    }
    for(int i=1;i<=a10;++i){
        b = b|(b<<10);b[10]=1;
    }
    for(int i=1;i<=a20;++i){
        b = b|(b<<20);b[20]=1;
    }
    //cerr<<b<<endl;
    cout<<"Total="<<b.count()<<endl;

    return 0;
}