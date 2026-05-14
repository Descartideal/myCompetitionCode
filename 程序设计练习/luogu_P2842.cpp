#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
	int n,w;cin>>n>>w;
	vector<int> a(n);for(int& x:a)cin>>x;
	
	vector<int> dp(w+1,INF);
	dp[0] = 0;
	
	for(int coin:a){
		for(int i=coin;i<=w;++i){
			dp[i] = min(dp[i],dp[i-coin]+1);
		}
	}
	
	cout<<dp[w]<<endl;
	
	return 0;
}
