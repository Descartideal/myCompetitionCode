#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
};

static inline ll C2(ll s) { return s * (s - 1) / 2; }

void solve(){
    int n; 
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
    vector<vector<int>> by(n);
    by.assign(n, {});
    for(int i = 0; i < n - 1; ++i){
        int v = abs(p[i] - p[i + 1]);
        by[v].push_back(i);
    }

    DSU dsu(n);
    ll cur = 0;
    vector<ll> ans(n, 0);

    auto unite = [&](int x, int y){
        int rx = dsu.find(x), ry = dsu.find(y);
        if(rx == ry) return;
        ll a = dsu.sz[rx], b = dsu.sz[ry];
        cur -= C2(a) + C2(b);
        if(dsu.sz[rx] < dsu.sz[ry]) swap(rx, ry);
        dsu.p[ry] = rx;
        dsu.sz[rx] += dsu.sz[ry];
        cur += C2((ll)dsu.sz[rx]);
    };

    for(int k = n - 1; k >= 1; --k){
        for(int idx : by[k]){
            unite(idx, idx + 1);
        }
        ans[k] = cur;
    }

    for(int k = 1; k <= n - 1; ++k){
        cout<<ans[k]<<(k==n-1 ? '\n':' ');
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
    int t;cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}

/*
***** Orz  Kiropo *******
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
//————自由是遗忘的左伴随
