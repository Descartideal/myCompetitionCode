#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    ll c;
    string s;
    cin >> n >> c >> s;

    if (s[0] == '0' || s.back() == '0') {
        // f(w) = 0, always divisible by c
        cout << "-1\n";
        return;
    }

    ll f_mod = 1;   // f(w) mod MOD
    ll f_c = 1;     // f(w) mod c

    for (int i = 1; i <= n - 1; ++i) {
        // w_i corresponds to s[i-1]
        ll x;
        if (s[i - 1] == '1') {
            x = 2;
        } else { // s[i-1] == '0'
            x = i - 1;   // i >= 1, but for i=1 we already handled w1=1, so i>=2 here
        }
        f_mod = f_mod * x % MOD;
        f_c = f_c * x % c;
    }

    if (f_c == 0) {
        cout << "-1\n";
    } else {
        cout << f_mod << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}