#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 Z = 998244353;

int main(){
    int a=1,b=1,c,d;

    for(int i=1;i<114514;++i){
        c = b;
        d = (a+b) % Z;
        a=c;b=d;
    }
    cout<<a<<endl;

    return 0;
}