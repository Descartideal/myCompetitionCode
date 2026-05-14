#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	vector<vector<int>> b(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;++i){
		b[0][i] = 1;
	}
	for(int i=1;i<=n-1;++i){
		for(int j = i+1;j<=n;++j){
			cin>>b[i][j];
		}
	}
	
	vector<int>dp(n+1,0);
	vector<int>dpi(n+1,0);
	int mx = INT_MIN ;
	int mxi = 0;
	for(int i=1;i<=n;++i){
		for(int j = i-1;j>=0;--j){
			if(b[j][i]==0)continue;
			if(dp[i]<dp[j]+a[i]){
				dp[i] = dp[j]+a[i];
				dpi[i] = j;
			}
		}
		if(mx<dp[i]){
			mx = dp[i];mxi = i;
		}
	}
	
	vector<int>temp;
	int i = mxi;
	while(i!=0){
		temp.push_back(i);
		i = dpi[i];
	}
	
	for(int i = temp.size()-1;i>=0;--i){
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	cout<<mx<<endl;
	
	return 0;
}
