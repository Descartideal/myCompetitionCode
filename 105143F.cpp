#include <bits/stdc++.h>
using namespace std;

int n;

bool query(int r,int c,int x){
    cout<<"? "<<r<<" "<<c<<" "<<x<<endl;
    bool t;cin>>t;
    return t;
}

int check(int x){
    vector<int> a(n+1,0);
    int r=n,c=1;
    while(1){
        bool t=query(r,c,x);
        if(t){
            a[c] = r;
            c++;
        }else{
            r--;
        }
        if(r<=0 || c>n){
            break;
        }
    }
    int res = accumulate(a.begin(),a.end(),0);
    return res;
}

int main(){
    int k;cin>>n>>k;
    k = n*n+1-k;
    int l=1,r=n*n,mid=(l+r)/2;
    while(l<r){
        int t = check(mid);
        if(t<k){
            l = mid+1;
        }else{
            r = mid;
        }
        mid=(l+r)/2;
    }
    cout<<"! "<<mid<<endl;
    return 0;
}