#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; 
	if(!(cin>>T)) return 0;
	while(T--){
		int n; cin>>n;
		vector<ll>a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<ll> pref(n+1,0);
		for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
		ll base = pref[n];
		ll bestGain = 0; // 不做操作也允许
		// 初始化 minX = min over x in [0..0] of x(x+1)-pref[x], i.e. x=0
		ll minVal = 0 * 1 - pref[0]; // =0
		for(int r=1;r<=n;r++){
			ll valR = 1ll*r*(r+1) - pref[r];
			ll gain = valR - minVal;
			if(gain > bestGain) bestGain = gain;
			// 更新 minVal 插入 x = r: x = r gives (r(r+1) - pref[r]) for future r' > r
			ll candidate = 1ll*r*(r+1) - pref[r];
			if(candidate < minVal) minVal = candidate;
		}
		cout << base + bestGain << '\n';
	}
	return 0;
}

