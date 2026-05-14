#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static const int LIM = 1500000; // sqrt(2e12) < 1.5e6
vector<int> primes;
bitset<LIM + 1> is_comp;

void sieve() {
    for (int i = 2; i <= LIM; ++i) {
        if (!is_comp[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * i * p > LIM) break;
            is_comp[i * p] = 1;
            if (i % p == 0) break;
        }
    }
}

vector<pair<int64, int>> factorize(int64 x) {
    vector<pair<int64, int>> fac;
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            int c = 0;
            while (x % p == 0) {
                x /= p;
                ++c;
            }
            fac.push_back({p, c});
        }
    }
    if (x > 1) fac.push_back({x, 1});
    return fac;
}

void gen_divisors(int idx, int64 cur, const vector<pair<int64, int>>& fac, vector<int64>& divs) {
    if (idx == (int)fac.size()) {
        divs.push_back(cur);
        return;
    }
    auto [p, e] = fac[idx];
    int64 v = 1;
    for (int i = 0; i <= e; ++i) {
        gen_divisors(idx + 1, cur * v, fac, divs);
        v *= p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int T;
    cin >> T;
    while (T--) {
        int n;
        int64 k;
        cin >> n >> k;

        vector<int> a(n);
        int mx = 0;
        int64 sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
            sum += a[i];
        }

        int64 S = sum + k;

        vector<int64> freq(mx + 1, 0), pcnt(mx + 1, 0), psum(mx + 1, 0);
        for (int x : a) freq[x]++;

        for (int i = 1; i <= mx; ++i) {
            pcnt[i] = pcnt[i - 1] + freq[i];
            psum[i] = psum[i - 1] + 1LL * freq[i] * i;
        }

        int64 ans = 1;

        // 情况1：x <= mx，O(mx log mx) 枚举所有 x
        for (int x = 1; x <= mx; ++x) {
            int64 need = 0;
            for (int j = x; j <= mx; j += x) {
                int l = j - x + 1;
                int64 cnt = pcnt[j] - pcnt[l - 1];
                int64 segsum = psum[j] - psum[l - 1];
                need += 1LL * j * cnt - segsum;
                if (need > k) break;
            }
            if (need <= k && (k - need) % x == 0) {
                ans = x;
            }
        }

        // 情况2：x > mx，只需枚举 S 的因子
        auto fac = factorize(S);
        vector<int64> divs;
        gen_divisors(0, 1, fac, divs);

        for (int64 d : divs) {
            if (d > mx && d * n <= S) {
                ans = max(ans, d);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}