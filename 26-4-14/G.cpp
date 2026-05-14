#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> prime;

int f(int x){
    if(x==1)return 1;
    for(int p:prime){
        if(x%p==0){
            int cnt = 0;
            while(x%p==0){
                x/=p;
                cnt++;
            }

            return (2*cnt+1)*( f(x) ) -cnt;
        }
    }
    return 2;
}

void solve(){
    int n;cin>>n;
    cout<<f(n)<<"\n";
}

signed main(){
    auto euler_Prime = [&](int n) -> void {
        vector<int> v(n + 1);
        for (int i = 2; i <= n; ++i) {
            if (!v[i]) {
                v[i] = i;
                prime.push_back(i);
            }
            for (int j = 0; j < prime.size(); ++j) {
                if (prime[j] > v[i] || prime[j] > n / i) break;
                v[i * prime[j]] = prime[j];
            }
        }
    };
    euler_Prime(200000);
    
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}