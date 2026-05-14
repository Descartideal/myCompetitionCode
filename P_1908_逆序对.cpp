#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
#define int long long

const int N = 1e6+20;

ll ans = 0;
int a[N],b[N];


void ms(int l,int r){
    if(l==r)return;
    int mid = (l+r)>>1;
    ms(l,mid);ms(mid+1,r);

    int pl = l,pr = mid+1;
    for(int i=l;i<=r;++i){
        if(pl>mid){
            b[i] = a[pr++];
        }else if(pr>r){
            b[i] = a[pl++]; 
        }else if(a[pl]<=a[pr]){
            b[i] = a[pl++]; 
        }else{
            b[i] = a[pr++];
            ans+=(mid-pl+1);
        }
    }

    for(int i=l;i<=r;++i){
        a[i] = b[i];
    }
    return;
}


signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    ms(1,n);
    cout<<ans<<endl;
    return 0;
}