#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template<class T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(const auto& x:v) os<<x<<" ";
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v){
    for(auto& x:v) is>>x;
    return is;
}

#define d(x) cerr<<"#---"<<#x<<"=="<<x<<endl;
#define cerr if(0)cerr

#define int long long

struct FastHashMap {
    static constexpr u64 EMPTY = ~0ULL;

    int SZ;                 // 表长（2 的幂）
    int MASK;
    vector<u64> key;
    vector<int> val;

    FastHashMap() : SZ(0), MASK(0) {}

    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    void init(int n) {
        // 为了降低冲突，开到 >= 4n 的最小 2 次幂
        SZ = 1;
        while (SZ < n * 4) SZ <<= 1;
        MASK = SZ - 1;
        key.assign(SZ, EMPTY);
        val.assign(SZ, 0);
    }

    void insert(u64 k, int v) {
        int p = splitmix64(k) & MASK;
        while (key[p] != EMPTY && key[p] != k) {
            p = (p + 1) & MASK;
        }
        key[p] = k;
        val[p] = v;
    }

    int get(u64 k) const {
        int p = splitmix64(k) & MASK;
        while (key[p] != k) {
            p = (p + 1) & MASK;
        }
        return val[p];
    }
};

inline void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n+1,0), b(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];

    vector<int> ls;
    ls.reserve(2*n);
    for(int i=1;i<=n;++i){
        ls.push_back(a[i]);
        ls.push_back(b[i]);
    }

    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());

    int m = (int)ls.size();

    FastHashMap mp;
    mp.init(m);
    for(int i=0;i<m;++i){
        mp.insert((u64)ls[i], i+1);   // rank 从 1 开始
    }

    vector<int> deltaA(m+2,0), deltaK(m+2,0);
    vector<int> A(m+2,0), K(m+2,0);

    for(int i=1;i<=n;++i){
        int l = mp.get((u64)a[i]);
        int r = mp.get((u64)b[i]);
        deltaA[r] -= 1;
        deltaK[l] += 1;
        deltaK[r] -= 1;
    }

    A[1] = n;
    for(int i=2;i<=m;++i){
        A[i] = A[i-1] + deltaA[i-1];
        K[i] = K[i-1] + deltaK[i-1];
    }

    int ans = 0;
    for(int i=1;i<=m;++i){
        if(K[i] > k) continue;
        ans = max(ans, A[i] * ls[i-1]);
    }

    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}