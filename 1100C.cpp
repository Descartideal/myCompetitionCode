#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define db(x) cerr<<"#---"<<#x<<"=="<<x<<endl;

const ld Pi = 4*atanl(1);

signed main(){
    int n,r;cin>>n>>r;
    ld celta = (ld)Pi/(ld)n;
    //db(celta);
    ld s = sinl(celta);
    ld R = r*s/(1-s);
    cout<<fixed<<setprecision(14)<<R<<endl;

    return 0;
}