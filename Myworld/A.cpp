#include <bits/stdc++.h>
using namespace std;

struct DynBitset {
    int nbits, W;
    vector<unsigned long long> a;

    DynBitset() {}
    DynBitset(int n): nbits(n), W((n + 63) >> 6), a(W, 0ULL) {}

    void reset() {
        fill(a.begin(), a.end(), 0ULL);
    }

    void set1(int pos) { // 1-based
        --pos;
        a[pos >> 6] |= 1ULL << (pos & 63);
    }

    bool test(int pos) const { // 1-based
        --pos;
        return (a[pos >> 6] >> (pos & 63)) & 1ULL;
    }

    void ORwith(const DynBitset &o) {
        for (int i = 0; i < W; ++i) a[i] |= o.a[i];
    }

    vector<int> bits() const {
        vector<int> res;
        for (int i = 0; i < W; ++i) {
            unsigned long long x = a[i];
            while (x) {
                int b = __builtin_ctzll(x);
                int pos = (i << 6) + b + 1;
                if (pos <= nbits) res.push_back(pos);
                x &= x - 1;
            }
        }
        return res;
    }
};

int solve_one(const string &s) {
    int n = (int)s.size();
    int B = n + 1; // positions 1..n are characters, n+1 is the right boundary

    vector<DynBitset> comp(2, DynBitset(B));
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0' || s[i - 1] == '2') comp[0].set1(i);
        if (s[i - 1] == '1' || s[i - 1] == '2') comp[1].set1(i);
    }

    // nxt[l] = { q | s[l..q-1] can be erased completely }, q=l means empty string
    vector<DynBitset> nxt(n + 2, DynBitset(B));
    nxt[n + 1].set1(n + 1);

    DynBitset I(B), J(B);

    for (int l = n; l >= 1; --l) {
        nxt[l].set1(l); // empty interval

        for (int c = 0; c < 2; ++c) {
            char need = char('0' + c);
            if (!(s[l - 1] == need || s[l - 1] == '2')) continue;

            // I = nxt[l+1] ∩ Pos[c]
            I.reset();
            for (int w = 0; w < I.W; ++w) {
                I.a[w] = nxt[l + 1].a[w] & comp[c].a[w];
            }

            // J = Pos[c] ∩ (union over i in I of nxt[i+1])
            J.reset();
            for (int i : I.bits()) {
                if (i + 1 <= n + 1) J.ORwith(nxt[i + 1]);
            }
            for (int w = 0; w < J.W; ++w) {
                J.a[w] &= comp[c].a[w];
            }

            // nxt[l] |= union over j in J of nxt[j+1]
            for (int j : J.bits()) {
                nxt[l].ORwith(nxt[j + 1]);
            }
        }
    }

    // DP on surviving subsequence
    // states of last two surviving chars:
    // (-1,-1), (-1,0), (-1,1), (0,0), (0,1), (1,0), (1,1)
    const int S = 7;
    vector<pair<int,int>> st = {
        {-1,-1}, {-1,0}, {-1,1}, {0,0}, {0,1}, {1,0}, {1,1}
    };
    map<pair<int,int>, int> id;
    for (int i = 0; i < S; ++i) id[st[i]] = i;

    const int INF = 1e9;
    vector<array<int, S>> dp(n + 2);
    for (int i = 0; i <= n + 1; ++i) dp[i].fill(INF);

    dp[0][id[{-1,-1}]] = 0;

    auto compat_char = [&](int pos, int c) -> bool {
        if (pos < 1 || pos > n) return false;
        return s[pos - 1] == char('0' + c) || s[pos - 1] == '2';
    };

    for (int u = 0; u <= n; ++u) {
        const DynBitset &row = (u == 0 ? nxt[1] : nxt[u + 1]);
        bool can_end = row.test(n + 1);
        vector<int> cand = row.bits();

        for (int sid = 0; sid < S; ++sid) {
            if (dp[u][sid] >= INF) continue;

            if (can_end) {
                dp[n + 1][sid] = min(dp[n + 1][sid], dp[u][sid]);
            }

            auto [a, b] = st[sid];

            for (int v : cand) {
                if (v == n + 1) continue; // this means ending, already handled

                for (int c = 0; c < 2; ++c) {
                    if (!compat_char(v, c)) continue;
                    if (a == c && b == c) continue; // would create 000 or 111

                    pair<int,int> ns = (b == -1 ? make_pair(-1, c) : make_pair(b, c));
                    int nid = id[ns];
                    dp[v][nid] = min(dp[v][nid], dp[u][sid] + 1);
                }
            }
        }
    }

    int ans = INF;
    for (int sid = 0; sid < S; ++sid) {
        ans = min(ans, dp[n + 1][sid]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << solve_one(s) << '\n';
    }
    return 0;
}