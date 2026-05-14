#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;cin>>n;
    vector<double> a(n),b(n),c(n);
    for(int i=0;i<n;++i){cin>>a[i]>>b[i]>>c[i];}
    double x;
    auto f = [&](double x){
        double res=-1e59;
        for(int i=0;i<n;++i){
            double t = a[i]*x*x+b[i]*x+c[i];
            if(t>res){
                res = t;
            }
        }
        return res;
    };

    double l=0,r=1000,ml=l+(r-l)/3,mr=l+2*(r-l)/3;
    auto g = [&](double& l,double& r,double& ml,double& mr){
        if(f(ml)<f(mr)){
            r=mr;
            ml=l+(r-l)/3,mr=l+2*(r-l)/3;
        }else{
            l=ml;
            ml=l+(r-l)/3,mr=l+2*(r-l)/3;
        }
    };
    

    bool j=1;
    for(int i=0;i<n;++i){
        if(fabs(a[i])>1e-12){
            j=0;break;
        }
    }
    if(j){
        if(f(l)<f(ml) && f(ml)<f(mr) && f(mr)<f(r)){
            cout<<fixed<<setprecision(4)<<f(l)<<endl;
            return;
        }
        if(f(l)>f(ml) && f(ml)>f(mr) && f(mr)>f(r)){
            cout<<fixed<<setprecision(4)<<f(r)<<endl;
            return;
        }
    }
    


    while (1) {
        g(l,r,ml,mr);
        if(r-l<1e-11)break;
    }
    cout<<fixed<<setprecision(4)<<f(mr)<<endl;
    return;
}

int main(){
    int t;cin>>t;
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    while (t--) {
        solve();
    }
    return 0;
}