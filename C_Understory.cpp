#include <bits/stdc++.h>
using namespace std;

signed main(){
    int q;cin>>q;
    multiset<int> t;
    while(q--){
        int op,h;cin>>op>>h;
        if(op==1){
            t.insert(h);
        }else{
            while((!t.empty()) && *t.begin()<=h){
                t.erase( (*t.begin()) );
            }
        }

        cout<<t.size()<<endl;
    }


    return 0;
}