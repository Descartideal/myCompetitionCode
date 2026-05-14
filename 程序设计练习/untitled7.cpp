#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Tcase;
	if(!(cin >> Tcase)) return 0;
	while(Tcase--){
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> a(n);
		long long sum = 0;
		long long Amax = 0;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			sum += a[i];
			Amax = max(Amax, a[i]);
		}
		
		int ans = 1;
		for(int s = n; s >= 1; --s){
			// minimal required total cards: at least sum and at least s*Amax
			long long need = max(sum, (long long)s * Amax);
			// round need up to nearest multiple of s
			long long blocks = (need + s - 1) / s; // g
			long long m = blocks * (long long)s;
			if(m <= sum + k){
				ans = s;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

