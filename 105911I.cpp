#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

const int M = 998244353;

ll mul(int a,int b){
    return a*b%M;
}

int powm(int a,int b){
    int x = a%M;
    int res = 1LL;
    while(b){
        if(b&1){
            res *= x;res%=M;
        }
        x = x*x;x%=M;
        b>>=1;
    }
    return res;
}

ll inv(int x){
    return powm(x,M-2)%M;
}

ll power(int x){
    int res = 1;
    while(x){
        res*=x--;res%=M;
    }
    return res;
}

ll C(int n,int k){
    if(n<k)return 0;
    if(n<1 || k<0){
        return 0;
    }
    return mul(  power(n)  ,  inv( mul(power(n-k),power(k)) )  );
}

int head(int n,int k,int h){
    if(n==k)return 0;
    if(h){
        return C(n-1,k);
    }else{
        k--;
        return C(n-1,k-1);
    }
}

int next(int n,int k,int h,int ti){
    if(n==k)return 0;
    if(n-1==k){
        if(h+ti==1){
            return 1;
        }else{
            return 0;
        }
    }
    if(h+ti==0){
        return C(n-2,k-2);
    }else if(h+ti==1){
        return C(n-2,k-1);
    }else{
        return C(n-2,k);
    }
}

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<bool> a(n+1,0);
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            a[i+1] = 1;
        }
    }
    vector<int> prea(n+1,0);
    for(int i=1;i<=n;++i){
        prea[i] = prea[i-1] + a[i];
    }

    int j=1;
    ll ans = 0;
    for(int i=1;i<=n;++i){
        while (prea[j]-prea[i]!=k && j<=n) {
            j++;
        }
        if(prea[j]-prea[i]==k){
            ans += head(j-i+1,k,a[i]);ans%=M;cerr<<ans<<"? "<<i<<" "<<j<<endl;
            j++;
        }
        
        while(prea[j]-prea[i]==k && j<=n){
            ans += next(j-i+1,k,a[i],a[j]);ans%=M;cerr<<ans<<endl;
            j++;
        }
    }
    cout<<ans<<endl;
    return;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}