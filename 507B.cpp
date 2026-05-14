#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
using ld = long double;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ld r,x1,y1,x2,y2;cin>>r>>x1>>y1>>x2>>y2;
  

    //db((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    ld d = sqrtl( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

    //db(d);
    //db(ceill(d/r));
    int cnt = ceill(ceill(d/r)/2.0);
    cout<<cnt<<endl;

    return 0;
}