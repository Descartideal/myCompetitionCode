#include <bits/stdc++.h>
using namespace std;
using ll = int;

inline ll inv_exgcd(ll a, ll p) {
	ll r0 = a, r1 = p;
	ll s0 = 1, s1 = 0;
	while (r1) {
		ll q = r0 / r1;
		ll r2 = r0 - q * r1; r0 = r1; r1 = r2;
		ll s2 = s0 - q * s1; s0 = s1; s1 = s2;
	}
	ll x = s0 % p;
	if (x < 0) x += p;
	return x;
}

inline void append_int_to_string(string &out, int x) {
	if (x == 0) { out.push_back('0'); return; }
	char buf[12];
	int pos = 0;
	while (x) {
		buf[pos++] = char('0' + (x % 10));
		x /= 10;
	}
	for (int i = pos - 1; i >= 0; --i) out.push_back(buf[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	ll n, p;
	if (!(cin >> n >> p)) return 0;
	
	string out;
	out.reserve((size_t)min<ll>(n, 3000000) * 8);
	
	for (ll i = 1; i <= n; ++i) {
		int inv = inv_exgcd((int)i, (int)p);
		append_int_to_string(out, inv);
		out.push_back('\n');
	}
	
	cout << out;
	return 0;
}

