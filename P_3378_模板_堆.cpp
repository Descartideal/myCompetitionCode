#include "bits/stdc++.h"
using namespace std;

#define int long long
const int INF = LONG_LONG_MAX;


signed main(){
    int n;cin>>n;
    vector<int> a;

    auto f = [&](int p){
         while (p>0) {
            int fa;fa=(p-1)/2;
            if(a[fa]>a[p]){
                swap(a[fa],a[p]);
                p=fa;
            }else{
                break;
            }
        }
    };

    for(int i=1;i<=n;++i){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;a.push_back(x);
            int p = a.size()-1;
            f(p);
           
        }else if(op==2){
            cout<<a[0]<<"\n";
        }else{
            a[0]=INF;
            int p=0;
            while (1) {
                if(2*p+2>a.size()-1){
                    if(2*p+1>a.size()-1){
                        ;
                    }else{
                        swap(a[p],a[2*p+1]);
                        p=2*p+1;
                    }
                    swap(a[p],a.back());
                    f(p);
                    a.pop_back();
                    break;
                }
                if(a[2*p+1]<a[2*p+2]){
                    swap(a[p],a[2*p+1]);
                    p=2*p+1;
                }else{
                    swap(a[p],a[2*p+2]);
                    p=2*p+2;
                }
            }
        }
    }
    return 0;
}