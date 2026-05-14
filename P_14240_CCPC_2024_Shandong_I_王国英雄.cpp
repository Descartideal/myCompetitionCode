#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

void solve(){
    int p , a , b , q , c , d , m , t;
    cin>>p>>a>>b>>q>>c>>d>>m>>t;

    int tleft = t;
    int dm = q - p;
    while(tleft >= 0){
        int x = min(m/p , (tleft - (b + d)) / (a + c));
        if(x <= 0){
            break;
        }
        else{
            int o = 0 , can1 = 0;
            int tmp1 = p - m % p;
            if(tmp1 % (dm*x) == 0){
                can1 = tmp1 / (dm*x);
            }
            else{
                can1 = tmp1 / (dm*x) + 1;
            }
            o = min(can1 , tleft / ((a + c) * x + (b + d)));

            m += o * dm * x;
            tleft -= o * ((a + c) * x + b + d);
        }
        //cout<<tleft<<endl;
    }
    cout<<m<<endl;

    return ;
}

signed main(){   
    ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
    int t;cin>>t;
    while (t--){
        solve();
    }
    return 0;
}